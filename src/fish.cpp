//
//  fish.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include <math.h>
#include "fish.hpp"

Fish::Fish(ofColor color) : Boid(color) {
    
}

void Fish::draw() {
    ofSetColor(color);

    ofVec3f pos = getPosition();
    ofVec3f velocity = getVelocity();
    float angle = atan2(velocity.y, velocity.x);
    
    ofPushMatrix();
    
    ofTranslate(pos);
    ofRotateRad(angle);
    ofVec2f p1(-size, size);
    ofVec2f p2(size * 3, 0);
    ofVec2f p3(-size, -size);
    ofDrawTriangle(p1, p2, p3);
    ofPopMatrix();  
}
