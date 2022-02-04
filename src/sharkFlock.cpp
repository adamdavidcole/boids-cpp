//
//  sharkFlock.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include "sharkFlock.hpp"

SharkFlock::SharkFlock(std::vector<Boid*> &s) : Flock(s) {
  
};

void SharkFlock::setup() {
    seperationW.addListener(this, &SharkFlock::seperationWChanged);
    cohesionW.addListener(this, &SharkFlock::cohesionWChanged);
    alignmentW.addListener(this, &SharkFlock::alignmentWChanged);
    separationThreshold.addListener(this, &SharkFlock::separationThresholdChanged);
    neighbourhoodSize.addListener(this, &SharkFlock::neighbourhoodSizeChanged);
    maxForce.addListener(this, &SharkFlock::maxForceChanged);
    maxSpeed.addListener(this, &SharkFlock::maxSpeedChanged);

    gui.setup(); // most of the time you don't need a name
    gui.add(seperationW.setup("seperationW", Shark::INITIAL_SEPARATION_WEIGHT, 0.0, 2.0));
    gui.add(cohesionW.setup("cohesionW", Shark::INITIAL_COHESION_WEIGHT, 0.0, 2.0));
    gui.add(alignmentW.setup("alignmentW", Shark::INITIAL_ALIGHNMENT_WEIGHT, 0.0, 2.0));
    gui.add(separationThreshold.setup("separationThreshold", Shark::INITIAL_SEPARATION_THRESHOLD, 0.1, 200.0));
    gui.add(neighbourhoodSize.setup("neighbourhoodSize", Shark::INITIAL_NEIGHBORHOOD_SIZE, 5.0, 200.0));
    gui.add(maxForce.setup("maxForce", Shark::INITIAL_MAX_FORCE, 0.001, 10.0));
    gui.add(maxSpeed.setup("maxSpeed", Shark::INITIAL_MAX_SPEED, 0.001, 10.0));
}


void SharkFlock::update(std::vector<Boid*> &f) {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        Shark* shark = (Shark*)boids[i];
        shark->update(boids, f, min, max);
    }
}


//--------------------------------------------------------------
void SharkFlock::seperationWChanged(float &seperationW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationWeight(seperationW);
    }
}
void SharkFlock::cohesionWChanged(float &cohesionW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setCohesionWeight(cohesionW);
    }
}
void SharkFlock::alignmentWChanged(float &alignmentW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setAlignmentWeight(alignmentW);
    }
}
void SharkFlock::separationThresholdChanged(float &separationThresholdChanged){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationThreshold(separationThresholdChanged);
    }
}
void SharkFlock::neighbourhoodSizeChanged(float &neighbourhoodSize){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setNeighbourhoodSize(neighbourhoodSize);
    }
}
void SharkFlock::maxSpeedChanged(float &maxSpeed){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxSpeed(maxSpeed);
    }
}
void SharkFlock::maxForceChanged(float &maxForce){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxForce(maxForce);
    }
}
