//
//  fishFlock.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include "fishFlock.hpp"

FishFlock::FishFlock(std::vector<Boid*> &f) : Flock(f) {
//    material.setEmissiveColor(ofFloatColor(20, 0 , 15));
//    material.setShininess(10);
    material.setDiffuseColor(ofColor::red);
    material.setAmbientColor(ofColor::red);
    material.setSpecularColor(ofColor::white);

    material.setShininess(128);
    
    light.setPointLight();
    light.setAttenuation(1.0340000, .001000, 0);


};

void FishFlock::update(std::vector<Boid*> &sharks) {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        Fish* fish = (Fish*)boids[i];
        fish->update(boids, sharks, min, max);
    }
//    
//    light.setAttenuation(((float)ofGetMouseX())/1000.0, ((float)(ofGetMouseY()))/1000.0, 0);
//    cout << to_string(((float)ofGetMouseX())/1000.0) << to_string(((float)(ofGetMouseY()))/1000.0) << endl;
}

void FishFlock::draw() {
    
    Boid* firstBoid = boids[0];
//
    ofVec3f lightPosition = firstBoid->position;
//
//    ofSetColor(255, 255, 255);
//    ofDrawSphere(lightPosition, 5);
    
    ofEnableLighting();
    light.enable();
    light.setPosition(lightPosition);
    material.setDiffuseColor(ofColor(255, 0 , 0));
    material.begin();

    for (int i = 0; i < boids.size(); i++)
    {
        material.setDiffuseColor(boids[i]->color);
        material.setAmbientColor(boids[i]->color);
        material.begin();

        boids[i]->draw();
    }
    
    material.end();
    light.disable();
    ofDisableLighting();
}
//
//void FishFlock::updateSharks(std::vector<Boid*> &sharks) {
//    ofVec3f min(0, 0);
//    ofVec3f max(ofGetWidth(), ofGetHeight());
//    for (int i = 0; i < boids.size(); i++)
//    {
//        Fish* fish = (Fish*)boids[i];
//        fish->updateSharks(sharks, min, max);
//    }
//}

ofVec3f FishFlock::separation(std::vector<Shark *> &sharks) {
    cout << "responding to sharks" <<endl;
}
