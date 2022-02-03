#include "testApp.h"

using namespace std;

testApp::testApp() {
    std::vector<Boid *> fishes;
    std::vector<Boid *> sharks;
    
    for (int i = 0; i < 50; i++) {
        Boid* fish = new Fish(ofColor(180, 20, 10));
        fishes.push_back(fish);
    }
    
    for (int i = 0; i < 3; i++) {
        Boid* shark = new Shark(ofColor(20, 100, 200));
        sharks.push_back(shark);
    }

    Flock* flock = new Flock(fishes);
    Flock* flock2 = new Flock(sharks);
    flocks.push_back(flock);
    flocks.push_back(flock2);
}

testApp::~testApp(){
    for (auto &flock : flocks) {
        for (auto &boid : flock->boids) {
            delete boid;
        }
        
        delete flock;
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0,50,50);

    for (auto &flock : flocks) {
        flock->setup();
    }
}


//--------------------------------------------------------------
void testApp::update() {
    for (auto &flock : flocks) {
        flock->update(flocks);
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    for (auto &flock : flocks) {
        flock->draw();
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
