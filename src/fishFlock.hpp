//
//  fishFlock.hpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#ifndef fishFlock_hpp
#define fishFlock_hpp

#include <stdio.h>
#include "flock.hpp"
#include "fish.hpp"
//#include "fish.hpp"

class FishFlock : public Flock {
public:
    FishFlock(std::vector<Boid*> &f);
    void update(std::vector<Boid*> &sharks);
    ofVec3f separation(std::vector<Shark *> &sharks);
};

#endif /* fishFlock_hpp */
