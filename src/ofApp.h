#pragma once

#include "ofMain.h"
#include "Ball.h"

#include "ofxOpenCv.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector <Ball> groupOfBalls;
    ofVec2f g;
    
    ofVideoGrabber         vidGrabber;
    
    ofxCvColorImage            myColorImg;
    
    ofxCvGrayscaleImage     myGrayImage;
    ofxCvGrayscaleImage     myBackground;
    ofxCvGrayscaleImage     myGrayDiff;
    
    ofxCvContourFinder     contourFinder;
    
    
    
    int                 threshold;
    bool                bLearnBackground;
    bool                bShowVideo = true;
   
		
};
