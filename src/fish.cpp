//
//  fish.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include <math.h>
#include "fish.hpp"

Fish::Fish(ofColor color) : Boid(color) {
    light.setAmbientColor(ofColor(0, 0, 0));
    
}

void Fish::draw() {
    ofSetColor(color);
//    ofSetColor(255, 255, 255, 50);

//    light.enable();
//    light.setPosition(particles[0].position);

//    for(unsigned int i = 0; i < particles.size(); i++){
        //ofPushStyle();
        //ofSetColor(particles[i].color);
//        material.setDiffuseColor(color);
//
//        material.begin();

    ofVec3f pos = getPosition();
    ofVec3f velocity = getVelocity();
    float angle = atan2(velocity.y, velocity.x);
    float angle2 = atan2(velocity.z, velocity.y);

//    ofPushMatrix();
//    ofTranslate(pos);
//    ofRotateZRad(angle + PI);
//    ofRotateXRad(angle2 + PI);
////    ofRotateRad(angle);
//
////    ofVec2f p1(-size, size);
////    ofVec2f p2(size * 3, 0);
////    ofVec2f p3(-size, -size);
//    ofDrawCone(ofVec3f(0,0,0), 5, 20);
//    ofPopMatrix();

    ofDrawSphere(pos.x, pos.y, pos.z, 5);
}

ofVec3f Fish::sharkSeperation(std::vector<Boid *> &otherBoids) {
    ofVec3f steer;
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);
        
        if ((d > 0) && (d < separationThreshold*4.0)) {
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
        average.normalize();
        average *= maxSpeed;
//        ofVec2f perpindicularAvg = ofVec2f(average).rotate(30);
//        perpindicularAvg *= maxSpeed;
        
        // get perpindiculat direction
        
        ofVec3f steer =  average - velocity;
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
    acceleration += 30.0 * sharkSeperation(sharks);
    acceleration += 10.0 * sharkAlignment(sharks);

    velocity += acceleration;
    velocity.limit(maxSpeed);
    position += velocity;
    acceleration *= 0.0;
    
    walls(min, max);
}
