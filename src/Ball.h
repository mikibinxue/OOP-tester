//
//  Ball.h
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#ifndef Ball_h
#define Ball_h

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework

class Ball{
public:
    
    void setup();
    void update();
    void display();
    void applyForce(ofVec2f force);
    bool checkEdges(ofVec2f centroid);
    
    
    //variables
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;

    int dim;
    ofColor color;
    bool if_close;
    
    Ball();
private:
};

#endif /* Ball_h */
