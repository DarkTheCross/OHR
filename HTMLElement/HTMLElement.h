#ifndef HTMLELEMENTS_H
#define HTMLELEMENTS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

typedef struct htmlrect{
    int top;
    int left;
    int width;
    int height;
} HTMLRect;

class HTMLElement{
protected:
    string ElementId;
    string ElementClass;
    string ElementType;

    string ElementInnerHTML;
    int ElementFontSize;

    Scalar ElementColor;
    string backgroundImage;
    bool hasBgImage;

    HTMLRect bounder;

public:
    vector<HTMLElement> children;
    HTMLElement();

    void setRect(int l, int t, int w, int h);
    HTMLRect getRect();
    void setId(string dId);
    string getId();
    void setClass(string dClass);
    string getClass();
    void setType(string dType);
    string getType();
    void setColor(Scalar& EColor);
    Scalar getColor();
    void setInnerHTML(string sih);
    string getInnerHTML();
    void setElementFontSize(int efs);

    void appendChild(HTMLElement& child);
    void setbgImage(string bgImage);

    string HTMLString();
    string CSSString();
};

#endif