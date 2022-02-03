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
    void draw();
};

#endif /* shark_hpp */
