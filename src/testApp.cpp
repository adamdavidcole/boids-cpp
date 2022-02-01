#include "testApp.h"

using namespace std;

testApp::~testApp(){}

//--------------------------------------------------------------
void testApp::setup(){
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0,50,50);

    flock.setup();
    flock2.setup();
}


//--------------------------------------------------------------
void testApp::update(){
    flock.update();
    flock2.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    flock.draw();
    flock2.draw();
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
