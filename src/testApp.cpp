#include "testApp.h"

using namespace std;

testApp::testApp() {
    std::vector<Boid *> fishes;
    std::vector<Boid *> sharks;
    
    for (int i = 0; i < 250; i++) {
        Fish* fish = new Fish(ofColor(180, 20, 10));
        fishes.push_back(fish);
    }
    
    for (int i = 0; i < 5; i++) {
        Shark* shark = new Shark(ofColor(20, 100, 200));
        sharks.push_back(shark);
    }
//
    fishFlock = new FishFlock(fishes);
    sharkFlock = new SharkFlock(sharks);
    

    //    flocks.push_back(flock);
//    flocks.push_back(flock2);
}

testApp::~testApp(){
    std::vector<Boid *> fishes = fishFlock->boids;
    for (int i = 0; i < fishes.size(); i++) {
        delete fishes[i];
    }
    delete fishFlock;
    
    std::vector<Boid *> sharks = sharkFlock->boids;
    for (int i = 0; i < sharks.size(); i++) {
        delete sharks[i];
    }
    delete sharkFlock;
    
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

    fishFlock->setup();
    sharkFlock->setup();
    
    for (auto &flock : flocks) {
        flock->setup();
    }
}


//--------------------------------------------------------------
void testApp::update() {
//    ((Flock*)fishFlock)->update();
    fishFlock->update(sharkFlock->boids);
    sharkFlock->update(fishFlock->boids);
    
//    fishFlock->updateSharks(sharkFlock->boids);
    
    for (auto &flock : flocks) {
        flock->update(flocks);
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    fishFlock->draw();
    sharkFlock->draw();
    
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
