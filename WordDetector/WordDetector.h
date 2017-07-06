#ifndef WORDDETECTOR_H
#define WORDDETECTOR_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "../HTMLElement/HTMLElement.h"

using namespace cv;
using namespace std;

class WordDetector{
public:

    WordDetector();

    static vector<HTMLElement> detectHTMLWords(char * imgName);
};

#endif