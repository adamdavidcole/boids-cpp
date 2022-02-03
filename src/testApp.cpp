#include "testApp.h"

using namespace std;

testApp::testApp() {
    cout << "begin testApp()" << endl;

    for (int i = 0; i < 50; i++) {
        Boid* fish = new Fish(ofColor(180, 20, 10));
        fishes.push_back(fish);
    }
    
    for (int i = 0; i < 3; i++) {
        Boid* shark = new Shark(ofColor(20, 100, 200));
        sharks.push_back(shark);
    }
    
    cout << "begin flock()" << endl;

    flock = new Flock(fishes);
    flock2 = new Flock(sharks);
    cout << "finished constructor" << endl;
//    f.setup();
//    flock = Flock(fish);
//    flock2 = Flock();
}

testApp::~testApp(){
    for (int i = 0; i < fishes.size(); i++) {
        delete fishes[i];
    }
    for (int i = 0; i < sharks.size(); i++) {
        delete sharks[i];
    }
    
    delete flock;
    delete flock2;
}

//--------------------------------------------------------------
void testApp::setup(){
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0,50,50);

    cout << "begin setup" << endl;
    flock->setup();
    cout << "end setup" << endl;

    flock2->setup();
}


//--------------------------------------------------------------
void testApp::update(){
    flock->update();
    flock2->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    flock->draw();
    flock2->draw();
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
