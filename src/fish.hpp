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

class Fish : public Boid {
private:
    float size = 5;
public:
    Fish(ofColor color);
    void draw();
};

#endif /* fish_hpp */
