//
//  shark.hpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#ifndef shark_hpp
#define shark_hpp

#include <stdio.h>
#include "boid.h"

class Shark : public Boid {
private:
    float size = 30;
public:
    Shark(ofColor color);
    void update(std::vector<Boid *> &otherBoids, std::vector<Boid*> &fish, ofVec3f &min, ofVec3f &max);
    void draw();
    
    static constexpr float INITIAL_SEPARATION_WEIGHT = 2.0;
    static constexpr float INITIAL_COHESION_WEIGHT = 0.75;
    static constexpr float INITIAL_ALIGHNMENT_WEIGHT = 0.5;
    static constexpr float INITIAL_SEPARATION_THRESHOLD = 100;
    static constexpr float INITIAL_NEIGHBORHOOD_SIZE = 50;
    static constexpr float INITIAL_MAX_FORCE = 2;
    static constexpr float INITIAL_MAX_SPEED = 3;
    
    ofVec3f fishCohesion(std::vector<Boid *> &otherBoids);
};

#endif /* shark_hpp */
