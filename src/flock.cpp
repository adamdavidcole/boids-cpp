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
//    for (int i = 0; i < boids.size(); i++)
//    {
//        delete boids[i];
//    }
}

void Flock::setup() {
    seperationW.addListener(this, &Flock::seperationWChanged);
    cohesionW.addListener(this, &Flock::cohesionWChanged);
    alignmentW.addListener(this, &Flock::alignmentWChanged);
    separationThreshold.addListener(this, &Flock::separationThresholdChanged);
    neighbourhoodSize.addListener(this, &Flock::neighbourhoodSizeChanged);
    maxForce.addListener(this, &Flock::maxForceChanged);
    maxSpeed.addListener(this, &Flock::maxSpeedChanged);
    
    radius.addListener(this, &Flock::radiusChanged);
    red.addListener(this, &Flock::redChanged);
    green.addListener(this, &Flock::greenChanged);
    blue.addListener(this, &Flock::blueChanged);
    alpha.addListener(this, &Flock::alphaChanged);
    colorRandomization.addListener(this, &Flock::colorRandomizationChanged);
    
//
    gui.setup(); // most of the time you don't need a name
    gui.add(seperationW.setup("seperationW", Boid::INITIAL_SEPARATION_WEIGHT, 0.0, 2.0));
    gui.add(cohesionW.setup("cohesionW", Boid::INITIAL_COHESION_WEIGHT, 0.0, 2.0));
    gui.add(alignmentW.setup("alignmentW", Boid::INITIAL_ALIGHNMENT_WEIGHT, 0.0, 2.0));
    gui.add(separationThreshold.setup("separationThreshold", Boid::INITIAL_SEPARATION_THRESHOLD, 0.1, 200.0));
    gui.add(neighbourhoodSize.setup("neighbourhoodSize", Boid::INITIAL_NEIGHBORHOOD_SIZE, 5.0, 200.0));
    gui.add(maxForce.setup("maxForce", Boid::INITIAL_MAX_FORCE, 0.001, 10.0));
    gui.add(maxSpeed.setup("maxSpeed", Boid::INITIAL_MAX_SPEED, 0.001, 10.0));
    
   
    gui.add(radius.setup("radius", Boid::INITIAL_RADIUS, 0.0001, 30.0));
    gui.add(red.setup("red", Boid::INITIAL_RED, 0, 255));
    gui.add(green.setup("green", Boid::INITIAL_GREEN, 0, 255));
    gui.add(blue.setup("blue", Boid::INITIAL_BLUE, 0, 255));
    gui.add(alpha.setup("alpha", Boid::INITIAL_ALPHA, 0, 255));
    gui.add(colorRandomization.setup("colorRandomization", Boid::INITIAL_COLOR_RANDOMIZATION, 0, 255));
}

void Flock::update() {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->update(boids, min, max);
    }
}

void Flock::update(std::vector<Flock *> flocks) {
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->update(flocks, min, max);
    }
}

void Flock::draw() {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->draw();
    }

//    gui.draw();
}


void Flock::drawGui() {
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

void Flock::radiusChanged(float &radius) {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setRadius(radius);
    }
}

void Flock::redChanged(float &red) {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->color.r = red;
    }
}
void Flock::greenChanged(float &green) {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->color.g = green;
    }
    std::cout << "green: " << ofToString(green) << std::endl;
}
void Flock::blueChanged(float &blue) {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->color.b = blue;
    }
}
void Flock::alphaChanged(float &alpha) {
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->color.a = alpha;
    }
}
void Flock::colorRandomizationChanged(float &colorRandomization) {
    for (int i = 0; i < boids.size(); i++)
    {
        float randR = ofRandom(-colorRandomization / 2.0, colorRandomization / 2.0);
        boids[i]->color.r = boids[i]->color.r + randR;
        
        float randG = ofRandom(-colorRandomization / 2.0, colorRandomization / 2.0);
        boids[i]->color.g = boids[i]->color.g + randG;
        
        float randB = ofRandom(-colorRandomization / 2.0, colorRandomization / 2.0);
        boids[i]->color.b = boids[i]->color.b + randB;
    }
}
