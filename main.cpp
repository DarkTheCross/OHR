#include "WordDetector/WordDetector.h"
#include "HTMLElement/HTMLElement.h"
#include "HTMLDocument/HTMLDocument.h"
#include "RectDetector/RectDetector.h"
#include "opencv2/core.hpp"
#include <iostream>

int main(int argc, char ** argv){
    if(argc == 1){
        HTMLElement testEle;
        //testEle.setColor(102,204,255);
        testEle.setRect(100,100,500,300);
        testEle.setId("test");
        testEle.setClass("group_test");
        testEle.setType("div");
        cout<<"HTML: "<<testEle.HTMLString()<<endl;
        cout<<"CSS: "<<testEle.CSSString()<<endl;
    } else {
        //system("rm -rf src");
        vector<vector<Point> > squares;
        vector<Scalar> scolor;
        RectDetector td;
        vector<HTMLElement> rectDivs = td.detectHTMLRects(argv[1]);
        WordDetector wd;
        vector<HTMLElement> wordDivs = wd.detectHTMLWords(argv[1]);
        //cout<<"Here!"<<endl;
        vector<HTMLElement> divs;
        for(size_t i = 0; i<rectDivs.size(); i++) {
            divs.push_back(rectDivs[i]);
        }
        for(size_t i = 0; i<wordDivs.size(); i++) {
            divs.push_back(wordDivs[i]);
        }
        sort(divs.begin(), divs.end(),
        [&](HTMLElement e1, HTMLElement e2){
            HTMLRect r1 = e1.getRect();
            HTMLRect r2 = e2.getRect();
            return r1.width*r1.height > r2.width*r2.height;
        });
        HTMLDocument hDoc;
        hDoc.setHTMLName(string("test.html"));
        hDoc.setCSSName(string("test.css"));
        for(size_t i = 0; i<divs.size(); i++) {
            hDoc.insertDiv(divs[i]);
        }
        hDoc.writeAll();
    }
    return 0;
}