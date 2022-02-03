#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"
#include "ofxGui.h"
#include "flock.hpp"

class testApp : public ofBaseApp{
	
public:
    testApp();
    ~testApp();
	
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    std::vector<Boid *> fishes;
    std::vector<Boid *> sharks;


    Flock* flock;
    Flock* flock2;
    
    
    static const int INITIAL_BOID_COUNT = 250;
};

#endif	
