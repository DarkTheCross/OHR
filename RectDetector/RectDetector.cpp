#include "RectDetector.h"

RectDetector::RectDetector(){
}

int thresh = 50;
int N = 11;

void RectDetector::findSquares( const Mat& image, vector<vector<Point> >& squares )
{
    squares.clear();

    Mat pyr, timg, gray0(image.size(), CV_8U), gray;

    // down-scale and upscale the image to filter out the noise
    pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
    pyrUp(pyr, timg, image.size());
    vector<vector<Point> > contours;

    // find squares in every color plane of the image
    for( int c = 0; c < 3; c++ )
    {
        int ch[] = {c, 0};
        mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                Canny(gray0, gray, 0, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                dilate(gray, gray, Mat(), Point(-1,-1));
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

            vector<Point> approx;

            // test each contour
            for( size_t i = 0; i < contours.size(); i++ )
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( approx.size() == 4 &&
                    fabs(contourArea(Mat(approx))) > 1000 &&
                    isContourConvex(Mat(approx)) )
                {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.3 )
                        squares.push_back(approx);
                }
            }
        }
    }
}

double RectDetector::angle( Point pt1, Point pt2, Point pt0 )
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

void RectDetector::filterSquares(vector<vector<Point> > & squares, int rangeThresh, Size is)
{
    for(size_t i = 0; i<squares.size(); i++) {
        for(size_t j = 0; j<squares[i].size(); j++) {
            for(size_t k = j+1; k<squares[i].size(); k++) {
                if(squares[i][j].x + squares[i][j].y > squares[i][k].x + squares[i][k].y + 2 * rangeThresh){
                    iter_swap(squares[i].begin()+j, squares[i].begin()+k);
                }
            }
        }
        if(squares[i][1].x > squares[i][2].x + rangeThresh) {
            iter_swap(squares[i].begin()+1, squares[i].begin()+2);
        }
        iter_swap(squares[i].begin()+3, squares[i].begin()+2);
    }
    vector<vector<Point2d> > results;
    vector<Point2d> dummyRect;
    dummyRect.push_back(Point2d(0,0));
    dummyRect.push_back(Point2d(0,is.height-1));
    dummyRect.push_back(Point2d(is.width-1,is.height-1));
    dummyRect.push_back(Point2d(is.width-1,0));
    results.push_back(dummyRect);
    vector<int> weight;
    for(size_t i = 0; i<squares.size(); i++) {
        size_t jpos = 0;
        bool found = false;
        for(size_t j = 0; j<results.size(); j++) {
            if(abs( double(squares[i][0].x) - results[j][0].x ) < double(rangeThresh) && abs( double(squares[i][0].y) - results[j][0].y ) < double(rangeThresh) ) {
                if(abs( double(squares[i][3].x) - results[j][3].x ) < double(rangeThresh) && abs( double(squares[i][3].y) - results[j][3].y ) < double(rangeThresh) ) {
                    found = true;
                    jpos = j;
                    break;
                }
            }
        }
        if(!found) {
            vector<Point2d> tmpRes;
            for(size_t k = 0; k<squares[i].size(); k++) {
                tmpRes.push_back(Point2d(double(squares[i][k].x), double(squares[i][k].y)));
            }
            results.push_back(tmpRes);
            weight.push_back(1);
        } else {
            for(size_t k = 0; k<results[jpos].size(); k++) {
                results[jpos][k].x = (results[jpos][k].x * double(weight[jpos]) + double(squares[i][k].x))/double(weight[jpos]+1);
                results[jpos][k].y = (results[jpos][k].y * double(weight[jpos]) + double(squares[i][k].y))/double(weight[jpos]+1);
            }
            weight[jpos] += 1;
        }
    }
    squares.clear();
    for(size_t i = 1; i<results.size(); i++) {
        vector<Point> tmpRes;
        for(size_t j = 0; j<results[i].size(); j++) {
            tmpRes.push_back(Point(int(results[i][j].x), int(results[i][j].y)));
        }
        squares.push_back(tmpRes);
    }
}

void RectDetector::detectSquares(char * imgName, vector<vector<Point> >& squares, vector<Scalar>& scolor)
{
    squares.clear();
    scolor.clear();
    Mat image = imread(imgName, 1);
    if( image.empty() )
    {
        cout << "Couldn't load."<<endl;
        return;
    }
    findSquares(image, squares);
    Size isize = image.size();
    filterSquares(squares, 10, isize);
    int pointCount;
    for(size_t i = 0; i<squares.size(); i++) {
        Scalar tmpColor(0,0,0,0);
        pointCount = 0;
        double tmpb = 0;
        double tmpg = 0;
        double tmpr = 0;
        for(size_t j = squares[i][0].x;  j< squares[i][2].x; j++){
            for(size_t k = squares[i][0].y; k<squares[i][2].y; k++){
                tmpb += double(image.at<Vec3b>(k, j)[0]);
                tmpg += double(image.at<Vec3b>(k, j)[1]);
                tmpr += double(image.at<Vec3b>(k, j)[2]);
                pointCount ++;
            }
        }
        tmpColor[0] = int(tmpb/pointCount);
        tmpColor[1] = int(tmpg/pointCount);
        tmpColor[2] = int(tmpr/pointCount);
        scolor.push_back(tmpColor);
    }
}

vector<HTMLElement> RectDetector::detectHTMLRects(char * imgName) {
    vector<vector<Point> > squares;
    vector<Scalar> scolor;
    detectSquares(imgName, squares, scolor);
    Mat image = imread(imgName, 1);
    vector<HTMLElement> divs;
    int idIter = 0;
    Mat subImg;
    for(size_t i = 0; i<squares.size(); i++)
    {
        HTMLElement tmpElement;
        tmpElement.setRect(squares[i][0].x, squares[i][0].y, squares[i][2].x-squares[i][0].x, squares[i][2].y - squares[i][0].y);
        char a[20];
        sprintf(a, "%d", idIter);
        tmpElement.setId(string("divRect")+string(a));
        tmpElement.setClass("ColorDiv");
        tmpElement.setType("div");
        tmpElement.setColor(scolor[i]);
        //subImg = image(Rect(squares[i][0].x, squares[i][0].y, squares[i][2].x-squares[i][0].x, squares[i][2].y - squares[i][0].y));
        //string src("src/");
        //src += string(a);
        //src += string(".png");
        //imwrite(src.c_str(),subImg);
        //tmpElement.setbgImage(src);
        divs.push_back(tmpElement);
        idIter++;
    }
    return divs;
}