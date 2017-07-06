#ifndef RECTDETECTOR_H
#define RECTDETECTOR_H

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include "../HTMLElement/HTMLElement.h"

using namespace cv;
using namespace std;

class RectDetector{
public:

    RectDetector();

    static double angle( Point pt1, Point pt2, Point pt0 );

    static void findSquares( const Mat& image, vector<vector<Point> >& squares );

    static void filterSquares(vector<vector<Point> > & squares, int rangeThresh, Size is);

    static void detectSquares(char * imgName, vector<vector<Point> >& squares, vector<Scalar>& scolor);

    static vector<HTMLElement> detectHTMLRects(char * imgName);
};

#endif