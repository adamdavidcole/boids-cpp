#include "testApp.h"

using namespace std;

testApp::testApp() {
    std::vector<Boid *> fishes;
    std::vector<Boid *> sharks;
    
    
    int fishCount = 250;
    for (int i = 0; i < fishCount; i++) {
        Fish* fish = new Fish(ofColor(Fish::INITIAL_RED, Fish::INITIAL_GREEN, Fish::INITIAL_BLUE));
        fishes.push_back(fish);
    }
    
//    int sharkCount = 5;
    int sharkCount = 5;
    for (int i = 0; i < sharkCount; i++) {
        Shark* shark = new Shark(ofColor(20, 100, 200));
        sharks.push_back(shark);
    }

    fishFlock = new FishFlock(fishes);
    sharkFlock = new SharkFlock(sharks);
    
    
    ofBackground(10);
    ofSetBackgroundAuto(false);
//    ofSetBackgroundAuto(true);
//    ofSetBackgroundColor(20);
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
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
    
    ofSetVerticalSync(true);

    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();

    ofSetCircleResolution(64);

    fishFlock->setup();
    sharkFlock->setup();
    
    for (auto &flock : flocks) {
        flock->setup();
    }
    
   // cam.setPosition(0, 0, -1000);
    
    backgroundAlpha.addListener(this, &testApp::backgroundAlphaChanged);
    
    gui.setup();
    gui.add(backgroundAlpha.setup("background alpha", 10, 0, 255));

}


//--------------------------------------------------------------
void testApp::update() {
//    ((Flock*)fishFlock)->update();
    fishFlock->update(sharkFlock->boids);
//    sharkFlock->update(fishFlock->boids);
    
//    fishFlock->updateSharks(sharkFlock->boids);
    
    for (auto &flock : flocks) {
        flock->update(flocks);
    }
//
//    ofVec3f camPos = cam.getPosition();
//    camPos = camPos.rotate(0.25, ofVec3f(0,1,0));
//    cam.setPosition(camPos);
//    cam.rotate(10, ofVec3f(0, 1, 0));
//    cam.lookAt(ofVec3f(0,0,0));
}

//--------------------------------------------------------------
void testApp::draw() {
    if (shouldClear) {
        ofClear(0,255);

        shouldClear = false;
        
        cout << "CLLEArR" << endl;
    }
    
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    ofSetColor(ofColor(15, 15, 15, backgroundAlphaVal));
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    
//    ofBackground(20);
//    cam.begin();
//    ofSetConeResolution(20, 2);
//    ofSetCylinderResolution(20, 2);
//    ofEnableDepthTest();
//    ofSetColor(ofColor::red);//RIGHT
//    ofDrawCone(100, 0, 0, 50, 100);
//
//    ofSetColor(ofColor::white);//LEFT
//    ofDrawSphere(-100, 0, 0, 50);
//
//    ofSetColor(ofColor::blue);//BOTTOM
//    ofDrawBox(0, 100, 0, 100);
//
//    ofSetColor(ofColor::cyan);//TOP
//    ofDrawCylinder(0, -100, 0, 50, 100);
//
//    ofSetColor(ofColor::yellow);//FRONT
//    ofDrawBox(0, 0, 100, 100);
//
//    ofSetColor(ofColor::magenta);//BACK
//    ofDrawBox(0, 0, -100, 100);
//
//    ofDrawGrid(20,10,true,true,true,true);
//    ofDisableDepthTest();
//
    ofEnableBlendMode(OF_BLENDMODE_ADD);
//
    fishFlock->draw();
//    sharkFlock->draw();
    
    ofDisableBlendMode();

    
//    cam.end();
    
   ofDisableDepthTest();
    
    
    fishFlock->drawGui();
    gui.draw();
    sharkFlock->drawGui();

    
//    for (auto &flock : flocks) {
//        flock->draw();
//    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        
        string fileName = "snapshot_"+ofGetTimestampString()+".png";
        img.save(fileName);
        
        std::cout << "Saved image: " << fileName << std::endl;
    }
    
    if (key == 'c') {
        shouldClear = true;
    }
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

//--------------------------------------------------------------
void testApp::backgroundAlphaChanged(float &bAlpha) {
    backgroundAlphaVal = bAlpha;
}
