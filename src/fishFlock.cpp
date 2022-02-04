//
//  fishFlock.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include "fishFlock.hpp"

FishFlock::FishFlock(std::vector<Boid*> &f) : Flock(f) {};

void FishFlock::update(std::vector<Boid*> &sharks) {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        Fish* fish = (Fish*)boids[i];
        fish->update(boids, sharks, min, max);
    }
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
