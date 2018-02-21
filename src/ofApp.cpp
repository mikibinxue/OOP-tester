#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //for opencv
    vidGrabber.setup(ofGetWidth(),ofGetHeight());
    
    
    myColorImg.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myGrayImage.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myBackground.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myGrayDiff.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    
    bLearnBackground = true;
    threshold = 150;
    ofSetBackgroundAuto(false);
    
    //for ball
    for(int i=0; i<10; i++){
        Ball temp;
        groupOfBalls.push_back(temp);
    }
    
    for(int i=0; i<10; i++){
        groupOfBalls[i].setup();
    }
    
    g.set(0,0.001);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //for opencv
    bool bNewFrame = false;
    
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    if (bNewFrame){
        
        
        myColorImg.setFromPixels(vidGrabber.getPixels());
        
        myGrayImage = myColorImg;
        if (bLearnBackground == true){
            myBackground = myGrayImage;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBackground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        myGrayDiff.absDiff(myBackground, myGrayImage);
        myGrayDiff.threshold(threshold);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(myGrayDiff, 20, (ofGetWidth()*ofGetHeight())/10, 5, false);
       
    }
    
    //for the balls
    //for balls
    for(int i=0; i<10; i++){
        groupOfBalls[i].applyForce(g);
        groupOfBalls[i].update();
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    //for opencv
    ofBackground(255);
    
    // draw the incoming video image
    ofSetHexColor(0xffffff);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - myColorImg.getWidth()/2,ofGetHeight()/2 - myColorImg.getHeight()/2);
    /*
     uncomment this to turn on the video background
     */
//    if(bShowVideo){
//        myColorImg.draw(0,0);
//    }
    

    for(auto &blob : contourFinder.blobs){
        ofSetColor(ofColor::violet);
        ofFill();
        ofDrawEllipse(blob.centroid, 20,20);
        //update the ball
        //for balls
        
        
        ofVec2f temp_centroid;
        temp_centroid.set(blob.centroid.x,blob.centroid.y);
        
        for(int i=0; i<10; i++){
            if(groupOfBalls[i].checkEdges(temp_centroid)){
                groupOfBalls[i].color.set(0);
            };
            groupOfBalls[i].update();
            groupOfBalls[i].display();
        }

        

    }
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
