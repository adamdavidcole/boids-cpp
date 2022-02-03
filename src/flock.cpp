//
//  flock.cpp
//  boids
//
//  Created by Adam Cole on 2/1/22.
//

#include "flock.hpp"

Flock::Flock() {}
Flock::Flock(std::vector<Boid *> &b) : boids(b) {}

Flock::~Flock() {
    for (int i = 0; i < boids.size(); i++)
    {
        delete boids[i];
    }
}

void Flock::setup() {
    seperationW.addListener(this, &Flock::seperationWChanged);
    cohesionW.addListener(this, &Flock::cohesionWChanged);
    alignmentW.addListener(this, &Flock::alignmentWChanged);
    separationThreshold.addListener(this, &Flock::separationThresholdChanged);
    neighbourhoodSize.addListener(this, &Flock::neighbourhoodSizeChanged);
    maxForce.addListener(this, &Flock::maxForceChanged);
    maxSpeed.addListener(this, &Flock::maxSpeedChanged);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(seperationW.setup("seperationW", Boid::INITIAL_SEPARATION_WEIGHT, 0.0, 2.0));
    gui.add(cohesionW.setup("cohesionW", Boid::INITIAL_COHESION_WEIGHT, 0.0, 2.0));
    gui.add(alignmentW.setup("alignmentW", Boid::INITIAL_ALIGHNMENT_WEIGHT, 0.0, 2.0));
    gui.add(separationThreshold.setup("separationThreshold", Boid::INITIAL_SEPARATION_THRESHOLD, 0.1, 200.0));
    gui.add(neighbourhoodSize.setup("neighbourhoodSize", Boid::INITIAL_NEIGHBORHOOD_SIZE, 5.0, 200.0));
    gui.add(maxForce.setup("maxForce", Boid::INITIAL_MAX_FORCE, 0.001, 10.0));
    gui.add(maxSpeed.setup("maxSpeed", Boid::INITIAL_MAX_SPEED, 0.001, 10.0));

    ofColor color = ofColor(ofRandom( 0, 255 ), 0, ofRandom( 128, 255 ));
    
    for (int i = 0; i < INITIAL_BOID_COUNT; i++)
    {
        Boid* fish = new Shark(color);
        boids.push_back(fish);
    }
}

void Flock::update() {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->update(boids, min, max);
    }
}

void Flock::draw() {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->draw();
    }

    gui.draw();
}


//--------------------------------------------------------------
void Flock::seperationWChanged(float &seperationW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationWeight(seperationW);
    }
}
void Flock::cohesionWChanged(float &cohesionW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setCohesionWeight(cohesionW);
    }
}
void Flock::alignmentWChanged(float &alignmentW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setAlignmentWeight(alignmentW);
    }
}
void Flock::separationThresholdChanged(float &separationThresholdChanged){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationThreshold(separationThresholdChanged);
    }
}
void Flock::neighbourhoodSizeChanged(float &neighbourhoodSize){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setNeighbourhoodSize(neighbourhoodSize);
    }
}
void Flock::maxSpeedChanged(float &maxSpeed){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxSpeed(maxSpeed);
    }
}
void Flock::maxForceChanged(float &maxForce){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxForce(maxForce);
    }
}
