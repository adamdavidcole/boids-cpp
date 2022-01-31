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

    gui.setup(); // most of the time you don't need a name
    gui.add(seperationW.setup("seperationW", 1.0, 0.0, 1.0));
    gui.add(cohesionW.setup("cohesionW", 0.2, 0.0, 1.0));
    gui.add(alignmentW.setup("alignmentW", 0.1, 0.0, 1.0));
    gui.add(separationThreshold.setup("separationThreshold", 10.0, 0.1, 30.0));
    gui.add(neighbourhoodSize.setup("neighbourhoodSize", 150.0, 50.0, 300.0));


	ofBackground(0,50,50);
	
	// set up the boids
	for (int i = 0; i < 50; i++)
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
    
    cout << seperationW << endl;
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
