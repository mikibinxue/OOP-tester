//
//  Ball.cpp
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#include "Ball.h"

Ball::Ball(){
    
}

void Ball:: setup(){

    
    position.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())-600);
    
    velocity.set(0,0);

    dim = 20;
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Ball::applyForce(ofVec2f _force){
    ofVec2f acc = _force/1;
    acceleration += acc;

}

void Ball::update(){
    velocity += acceleration;
    position += velocity;
        acceleration *= 0;
    
    
}

void Ball::display(){
    ofSetColor(color);
    //ofDrawCircle(position.x, position.y, dim);
    ofDrawBitmapString("rain", position.x, position.y);
}

bool Ball::checkEdges(ofVec2f _centroid){

    ofVec2f centroid;
    centroid = _centroid;
    
    float distance = position.distance(centroid);
    
    if(distance < 50){
        return true;
    };
    return false;
    
    
}

