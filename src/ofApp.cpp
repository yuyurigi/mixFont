#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(191, 163, 252);
    ofSetBackgroundAuto(true);
    ofSetFrameRate(5);
    
    //Load fonts
    mixedFont = std::make_shared<ofxMixedFont>();
    
    mplus = std::make_shared<ofxFT2Font>("MPLUSRounded1c-Regular.ttf", 40);
    emojiFont = std::make_shared<ofxFT2Font>("Apple_color_emoji.ttc", 40);
    
    mixedFont->add(mplus);
    mixedFont->add(emojiFont);
    
    typeStr = "あのイーハトーヴォの\nすきとおった風😊\n夏でも底に冷たさをもつ青いそら😇💕\nうつくしい森で飾られたモーリオ市💖✨\n郊外のぎらぎらひかる草の波😌🌱🌱🌱";
    frameCount = 0;
    frameCount2 = 0;
    
    y1 = 52;
    y2 = 110;
    
    wordCount = ofUTF8Length(typeStr);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ｜を描く
    if (frameCount <= wordCount) {
    //string ch2 = utf8_substr2(typeStr, frameCount-1, 1);
    ch2 = utf8_substr2(typeStr, frameCount-1, 1);
    x1 = 50 + frameCount2 * 54;
    x2 = 50 + frameCount2 * 54;
        if (ch2 == "\n") {
            x1 = 50;
            x2 = 50;
            frameCount2 = 0;
            y1 += 79;
            y2 += 79;
        }
        if (frameCount == 0){
            x1 = 50;
            x2 = 50;
            y1 = 52;
            y2 = 110;
        }
    ofSetLineWidth(5);
    ofDrawLine(x1, y1, x2, y2);
    } else {
        if(frameCount%5 == 3 || frameCount%5 == 4){
        ofDrawLine(x1, y1, x2, y2);
        }
    }
     
    //文字列の描画
    ch = utf8_substr2(typeStr, 0, frameCount);
    mixedFont->drawString(ch, ofPoint(50, 100));
    
    frameCount++;
    frameCount2++;

    myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
//日本語文字列のsubstr
//文字列 string の、start で指定された位置から length バイト分の文字列を返す
string ofApp::utf8_substr2(const string &str,int start, int length)
{
    int i,ix,j,realstart,reallength;
    if (length==0) return "";
    if (start<0 || length <0)
    {
        //find j=utf8_strlen(str);
        for(j=0,i=0,ix=str.length(); i<ix; i+=1, j++)
        {
            unsigned char c= str[i];
            if      (c>=0   && c<=127) i+=0;
            else if (c>=192 && c<=223) i+=1;
            else if (c>=224 && c<=239) i+=2;
            else if (c>=240 && c<=247) i+=3;
            else if (c>=248 && c<=255) return "";//invalid utf8
        }
        if (length !=INT_MAX && j+length-start<=0) return "";
        if (start  < 0 ) start+=j;
        if (length < 0 ) length=j+length-start;
    }
 
    j=0,realstart=0,reallength=0;
    for(i=0,ix=str.length(); i<ix; i+=1, j++)
    {
        if (j==start) { realstart=i; }
        if (j>=start && (length==INT_MAX || j<=start+length)) { reallength=i-realstart; }
        unsigned char c= str[i];
        if      (c>=0   && c<=127) i+=0;
        else if (c>=192 && c<=223) i+=1;
        else if (c>=224 && c<=239) i+=2;
        else if (c>=240 && c<=247) i+=3;
        else if (c>=248 && c<=255) return "";//invalid utf8
    }
    if (j==start) { realstart=i; }
    if (j>=start && (length==INT_MAX || j<=start+length)) { reallength=i-realstart; }
 
    return str.substr(realstart,reallength);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        frameCount = 0;
        frameCount2 = 0;
    }
    if (key == 'S' || key == 's') {
        myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.jpg");
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
