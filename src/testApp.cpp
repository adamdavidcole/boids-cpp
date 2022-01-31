#include "testApp.h"

using namespace std;

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
}

//--------------------------------------------------------------
void testApp::setup(){
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();
    
    seperationW.addListener(this, &testApp::seperationWChanged);
    cohesionW.addListener(this, &testApp::cohesionWChanged);
    alignmentW.addListener(this, &testApp::alignmentWChanged);
    separationThreshold.addListener(this, &testApp::separationThresholdChanged);
    neighbourhoodSize.addListener(this, &testApp::neighbourhoodSizeChanged);
    maxForce.addListener(this, &testApp::maxForceChanged);
    maxSpeed.addListener(this, &testApp::maxSpeedChanged);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(seperationW.setup("seperationW", Boid::INITIAL_SEPARATION_WEIGHT, 0.0, 2.0));
    gui.add(cohesionW.setup("cohesionW", Boid::INITIAL_COHESION_WEIGHT, 0.0, 2.0));
    gui.add(alignmentW.setup("alignmentW", Boid::INITIAL_ALIGHNMENT_WEIGHT, 0.0, 2.0));
    gui.add(separationThreshold.setup("separationThreshold", Boid::INITIAL_SEPARATION_THRESHOLD, 0.1, 200.0));
    gui.add(neighbourhoodSize.setup("neighbourhoodSize", Boid::INITIAL_NEIGHBORHOOD_SIZE, 5.0, 200.0));
    gui.add(maxForce.setup("maxForce", Boid::INITIAL_MAX_FORCE, 0.001, 10.0));
    gui.add(maxSpeed.setup("maxSpeed", Boid::INITIAL_MAX_SPEED, 0.001, 10.0));


	ofBackground(0,50,50);
	
	// set up the boids
	for (int i = 0; i < INITIAL_BOID_COUNT; i++)
    {
        boids.push_back(new Boid());
    }

}


//--------------------------------------------------------------
void testApp::update(){
	
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}

    gui.draw();
}

//--------------------------------------------------------------
void testApp::seperationWChanged(float &seperationW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationWeight(seperationW);
    }
}
void testApp::cohesionWChanged(float &cohesionW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setCohesionWeight(cohesionW);
    }
}
void testApp::alignmentWChanged(float &alignmentW){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setAlignmentWeight(alignmentW);
    }
}
void testApp::separationThresholdChanged(float &separationThresholdChanged){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setSeparationThreshold(separationThresholdChanged);
    }
}
void testApp::neighbourhoodSizeChanged(float &neighbourhoodSize){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setNeighbourhoodSize(neighbourhoodSize);
    }
}
void testApp::maxSpeedChanged(float &maxSpeed){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxSpeed(maxSpeed);
    }
}
void testApp::maxForceChanged(float &maxForce){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->setMaxForce(maxForce);
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
