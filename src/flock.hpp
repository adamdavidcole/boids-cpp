//
//  flock.hpp
//  boids
//
//  Created by Adam Cole on 2/1/22.
//

#ifndef flock_hpp
#define flock_hpp

#include <stdio.h>
#include "boid.h"
#include "ofxGui.h"

class Flock {
public:
    ~Flock();
    
    void setup();
    void update();
    void draw();
    
    static const int INITIAL_BOID_COUNT = 100;
    
    std::vector<Boid *> boids;
    
    ofxFloatSlider seperationW;
    ofxFloatSlider cohesionW;
    ofxFloatSlider alignmentW;
    
    ofxFloatSlider separationThreshold;
    ofxFloatSlider neighbourhoodSize;
    
    ofxFloatSlider maxSpeed;
    ofxFloatSlider maxForce;

    ofxPanel gui;
    
    void seperationWChanged(float & seperationW);
    void cohesionWChanged(float & cohesionW);
    void alignmentWChanged(float & alignmentW);
    void separationThresholdChanged(float &separationThresholdChanged);
    void neighbourhoodSizeChanged(float &neighbourhoodSize);
    void maxSpeedChanged(float &maxSpeed);
    void maxForceChanged(float &maxForce);
};

#endif /* flock_hpp */
