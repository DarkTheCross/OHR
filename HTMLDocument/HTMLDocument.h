#ifndef HTMLDOCUMENT_H
#define HTMLDOCUMENT_H

#include "../HTMLElement/HTMLElement.h"

using namespace std;
using namespace cv;

class HTMLDocument{
protected:
    string HTMLName;
    string CSSName;

    vector<HTMLElement> divs;
public:
    HTMLDocument();

    void insertDiv(HTMLElement& newDiv);
    void writeHTML();
    void writeCSS();
    void setHTMLName(string HName);
    void setCSSName(string CName);
    void writeAll();
};

#endif