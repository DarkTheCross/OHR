#include "HTMLElement.h"
using namespace std;
using namespace cv;

HTMLElement::HTMLElement(){
    this->ElementId = string("");
    this->ElementClass = string("");
    this->ElementType = string("div");
    this->ElementInnerHTML = string("");
    this->backgroundImage = string("");
    this->hasBgImage = false;
    this->ElementFontSize = 0;
    Scalar tmpColor;
    tmpColor[0] = 255;
    tmpColor[1] = 255;
    tmpColor[2] = 255;
    this->setColor(tmpColor);
}

void HTMLElement::setRect(int l, int t, int w, int h)
{
    this->bounder.left = l;
    this->bounder.top = t;
    this->bounder.width = w;
    this->bounder.height = h;
}

HTMLRect HTMLElement::getRect()
{
    return this->bounder;
}

Scalar HTMLElement::getColor()
{
    return this->ElementColor;
}

void HTMLElement::setColor(Scalar& EColor){
    this->ElementColor = EColor;
}

void HTMLElement::setId(string dId){
    this->ElementId = dId;
}

string HTMLElement::getId(){
    return this->ElementId;
}

void HTMLElement::setClass(string dClass){
    this->ElementClass = dClass;
}

string HTMLElement::getClass(){
    return this->ElementClass;
}

void HTMLElement::setType(string dType){
    this->ElementType = dType;
}

string HTMLElement::getType(){
    return this->ElementType;
}

void HTMLElement::appendChild(HTMLElement& child){
    this->children.push_back(child);
}

void HTMLElement::setInnerHTML(string sih)
{
    this->ElementInnerHTML = sih;
}

string HTMLElement::getInnerHTML()
{
    return this->ElementInnerHTML;
}

void HTMLElement::setElementFontSize(int efs){
    this->ElementFontSize = efs;
}

void HTMLElement::setbgImage(string bgImage){
    this->backgroundImage = bgImage;
    this->hasBgImage = true;
}

string HTMLElement::HTMLString(){
    string result;
    // begin tag
    result += string("<");
    result += this->ElementType;
    result += string(" ");
    // class and id
    result += string("class = \"");
    result += this->getClass();
    result += string("\" id = \"");
    result += this->getId();
    result += string("\">\n");
    // children
    result += this->ElementInnerHTML;
    result += string("\n");
    for(unsigned int i = 0; i < this->children.size(); i++) {
        result += this->children[i].HTMLString();
    }
    result += string("</");
    result += this->ElementType;
    result += string(">\n");
    return result;
}

string HTMLElement::CSSString(){
    string result("#");
    result += this->getId();
    //result += string(".");
    //result += this->getClass();
    result += string("\n{\n");
    stringstream ss;
    string tmpStr;

    result += string("display: block;\n");

    result += string("position: fixed;\n");
    char buffer[10];

    if(!this->hasBgImage){
        if(this->ElementInnerHTML == string("")){
            result += string("background-color: rgb(");
            Scalar EColor = this->getColor();
            ss<<int(EColor[2]);
            tmpStr = ss.str();
            ss.str("");
            result += tmpStr;
            result += string(", ");
            ss<<int(EColor[1]);
            tmpStr = ss.str();
            ss.str("");
            result += tmpStr;
            result += string(", ");
            ss<<int(EColor[0]);
            tmpStr = ss.str();
            ss.str("");
            result += tmpStr;
            result += string("); \n");
        }
    } else {
        result += string("background-image: url(");
        result += this->backgroundImage;
        result += string(");\n");

    }

    if(!(this->ElementInnerHTML == string(""))){
        result += string("font-size: ");
        ss<<this->ElementFontSize;
        tmpStr = ss.str();
        ss.str("");
        result += tmpStr;
        result += string("px;\n");
    }
    result += string("left: ");
    ss<<this->getRect().left;
    tmpStr = ss.str();
    ss.str("");
    result += tmpStr;
    result += string("px;\n");

    result += string("top: ");
    ss<<this->getRect().top;
    tmpStr = ss.str();
    ss.str("");
    result += tmpStr;
    result += string("px;\n");

    result += string("width: ");
    ss<<this->getRect().width;
    tmpStr = ss.str();
    ss.str("");
    result += tmpStr;
    result += string("px;\n");
    
    result += string("height: ");
    ss<<this->getRect().height;
    tmpStr = ss.str();
    ss.str("");
    result += tmpStr;
    result += string("px;\n");

    result += string("}\n");
    for(size_t i = 0; i<this->children.size(); i++) {
        result += this->children[i].CSSString();
    }
    return result;
}