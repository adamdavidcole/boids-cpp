//
//  sharkFlock.hpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#ifndef sharkFlock_hpp
#define sharkFlock_hpp

#include <stdio.h>
#include "flock.hpp"
#include "shark.hpp"

class SharkFlock : public Flock {
public:
    SharkFlock(std::vector<Boid*> &s);
    void update(std::vector<Boid*> &fish);
    void setup();
    void draw();
    
    void seperationWChanged(float & seperationW);
    void cohesionWChanged(float & cohesionW);
    void alignmentWChanged(float & alignmentW);
    void separationThresholdChanged(float &separationThresholdChanged);
    void neighbourhoodSizeChanged(float &neighbourhoodSize);
    void maxSpeedChanged(float &maxSpeed);
    void maxForceChanged(float &maxForce);
    
    ofLight light;
    ofMaterial material;
};

#endif /* sharkFlock_hpp */
