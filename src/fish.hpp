//
//  fish.hpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#ifndef fish_hpp
#define fish_hpp

#include <stdio.h>
#include "boid.h"
#include "shark.hpp"

class Fish : public Boid {
private:
    float size = 5;
public:
    Fish(ofColor color);
    void draw();
    void update(std::vector<Boid *> &otherBoids, std::vector<Boid*> &sharks, ofVec3f &min, ofVec3f &max);
    void updateSharks(std::vector<Boid*> &sharks, ofVec3f &min, ofVec3f &max);
    
    ofVec3f sharkSeperation(std::vector<Boid *> &otherBoids);
    ofVec3f sharkAlignment(std::vector<Boid *> &otherBoids);
    ofVec3f sharkCohesion(std::vector<Boid *> &otherBoids);
};

#endif /* fish_hpp */
