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

ofVec3f Fish::sharkSeperation(std::vector<Boid *> &otherBoids) {
    ofVec3f steer;
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);
        
        if ((d > 0) && (d < separationThreshold*2.0)) {
            ofVec3f diff = position - otherBoidPosition;
            diff /= d;
            steer += diff;
            count = count + 1;
        }
    }
    
    if (count > 0) {
        steer /= ((float) count);
    }
    
    if (steer.lengthSquared() > 0) {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }
    
    return steer;
}

ofVec3f Fish::sharkAlignment(std::vector<Boid *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);

        if ((d > 0) && (d < neighbourhoodSize/5.0))
        {
            average += otherBoid->getVelocity();
            count += 1;
        }
    }
    if (count > 0) {
        average /= ((float)count);
        ofVec2f perpindicularAvg = ofVec2f(average).rotate(30);
        perpindicularAvg *= maxSpeed;
        
        // get perpindiculat direction
        
        ofVec3f steer =  ofVec3f(perpindicularAvg) - velocity;
        steer.limit(maxForce);
        return steer;
    }
    
    return ofVec3f();
}

void Fish::updateSharks(std::vector<Boid*> &sharks, ofVec3f &min, ofVec3f &max) {
    acceleration += sharkSeperation(sharks);
}

void Fish::update(std::vector<Boid *> &otherBoids, std::vector<Boid*> &sharks, ofVec3f &min, ofVec3f &max)
{
    acceleration += separationWeight*separation(otherBoids);
    acceleration += cohesionWeight*cohesion(otherBoids);
    acceleration += alignmentWeight*alignment(otherBoids);
    acceleration += 20.0 * sharkSeperation(sharks);
    acceleration += 100.0 * sharkAlignment(sharks);

    velocity += acceleration;
    velocity.limit(maxSpeed);
    position += velocity;
    acceleration *= 0.0;
    
    walls(min, max);
}
