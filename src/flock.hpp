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
#include "fish.hpp"
#include "shark.hpp"
#include "ofxGui.h"

class Flock {
public:
    Flock();
    Flock(std::vector<Boid *> &b);
    ~Flock();
    
    virtual void setup();
    void update();
    void update(std::vector<Flock *> flocks);
    void draw();
    void drawGui();
    
    static const int INITIAL_BOID_COUNT = 100;
    
    std::vector<Boid *> boids;
    
    ofxFloatSlider seperationW;
    ofxFloatSlider cohesionW;
    ofxFloatSlider alignmentW;
    
    ofxFloatSlider separationThreshold;
    ofxFloatSlider neighbourhoodSize;
    
    ofxFloatSlider maxSpeed;
    ofxFloatSlider maxForce;
    
    ofxFloatSlider radius;
    ofxFloatSlider red;
    ofxFloatSlider green;
    ofxFloatSlider blue;
    ofxFloatSlider alpha;
    ofxFloatSlider colorRandomization;

    ofxPanel gui;
    
    void seperationWChanged(float & seperationW);
    void cohesionWChanged(float & cohesionW);
    void alignmentWChanged(float & alignmentW);
    void separationThresholdChanged(float &separationThresholdChanged);
    void neighbourhoodSizeChanged(float &neighbourhoodSize);
    void maxSpeedChanged(float &maxSpeed);
    void maxForceChanged(float &maxForce);
    
    void radiusChanged(float &radius);
    void redChanged(float &red);
    void greenChanged(float &green);
    void blueChanged(float &blue);
    void alphaChanged(float &alpha);
    void colorRandomizationChanged(float &colorRandomization);
};

#endif /* flock_hpp */
