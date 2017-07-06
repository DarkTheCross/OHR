#include "WordDetector.h"

WordDetector::WordDetector(){
}

vector<HTMLElement> WordDetector::detectHTMLWords(char * imgName){
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    // Open input image with leptonica library
    Pix *image = pixRead(imgName);
    api->SetImage(image);
    Boxa* boxes = api->GetComponentImages(tesseract::RIL_TEXTLINE, true, NULL, NULL);
    //printf("Found %d textline image components.\n", boxes->n);
    vector<HTMLElement> divs;
    for (int i = 0; i < boxes->n; i++) {
        BOX* box = boxaGetBox(boxes, i, L_CLONE);
        api->SetRectangle(box->x, box->y, box->w, box->h);
        char* ocrResult = api->GetUTF8Text();
        //int conf = api->MeanTextConf();
        //fprintf(stdout, "Box[%d]: x=%d, y=%d, w=%d, h=%d, confidence: %d, text: %s", i, box->x, box->y, box->w, box->h, conf, ocrResult);
        HTMLElement tmpDiv;
        tmpDiv.setRect(box->x, box->y, box->w, box->h);
        char a[20];
        sprintf(a, "%d", i);
        tmpDiv.setId(string("WordDivRect")+string(a));
        tmpDiv.setClass("WordDiv");
        tmpDiv.setType("div");
        tmpDiv.setElementFontSize(box->h);
        tmpDiv.setInnerHTML(string(ocrResult));
        //tmpDiv.setColor(scolor[i]);
        divs.push_back(tmpDiv);
    }

    // Destroy used object and release memory
    api->End();
    pixDestroy(&image);
    return divs;
}