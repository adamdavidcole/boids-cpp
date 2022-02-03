//
//  shark.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include "shark.hpp"

Shark::Shark(ofColor color) : Boid(color) {
    
}

void Shark::draw() {
    ofSetColor(color);

    ofVec3f pos = getPosition();
    
    ofPushMatrix();
    ofTranslate(pos);
    ofDrawCircle(0, 0, size);
    ofPopMatrix();
}
