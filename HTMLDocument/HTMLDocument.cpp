#include "HTMLDocument.h"
#include <fstream>

using namespace std;
using namespace cv;

HTMLDocument::HTMLDocument()
{
    this->HTMLName = "";
    this->CSSName = "";
    this->divs.clear();
}

void insertDivIter(vector<HTMLElement>& divVect, HTMLElement& newDiv){
    HTMLRect newDivRect = newDiv.getRect();
    HTMLRect iterRect;
    for(size_t i = 0; i<divVect.size(); i++) {
        iterRect = divVect[i].getRect();
        // Existing div contains the new div
        if(iterRect.left <= newDivRect.left && iterRect.left+iterRect.width >= newDivRect.left+newDivRect.width){
            if(iterRect.top <= newDivRect.top && iterRect.top+iterRect.height >= newDivRect.top+newDivRect.height){
                insertDivIter(divVect[i].children, newDiv);
                return;
            }
        }
    }
    divVect.push_back(newDiv);
}

void HTMLDocument::insertDiv(HTMLElement& newDiv){
    // divs should be inserted in the order of area size. 
    insertDivIter(this->divs, newDiv);
}

void HTMLDocument::writeHTML(){
    ofstream out;
    out.open(this->HTMLName.c_str(), ios::out|ios::trunc);
    if(!out.is_open()){
        cerr<<"Open file: "<<this->HTMLName<<" failed. "<<endl;
        return;
    }
    out<<"<!DOCTYPE html>\n";
    out<<"<html>\n<head>\n";
    out<<"<meta http-equiv=Content-Type content=\"text/html;charset=utf-8\" />";
    out<<"<title>"<<"1"<<"</title>\n";
    out<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"";
    out<<this->CSSName;
    out<<"\" charset = \"utf-8\"/ >\n</head>\n";
    out<<"<body>\n";

    for(size_t i = 0; i < this->divs.size(); i++){
        out<<this->divs[i].HTMLString();
    }

    out<<"</body>\n</html>\n";
    out.close();
}

void HTMLDocument::writeCSS(){
    ofstream out;
    out.open(this->CSSName.c_str(), ios::out|ios::trunc);
    for(size_t i = 0; i < this->divs.size(); i++){
        out<<this->divs[i].CSSString();
    }
    out.close();

}

void HTMLDocument::setHTMLName(string HName){
    this->HTMLName = HName;
}

void HTMLDocument::setCSSName(string CName){
    this->CSSName = CName;
}

void HTMLDocument::writeAll(){
    writeHTML();
    writeCSS();
}