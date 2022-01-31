#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"
#include "ofxGui.h"

class testApp : public ofBaseApp{
	
public:
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

    std::vector<Boid *> boids;
    
    static const int INITIAL_BOID_COUNT = 250;
	
    ofxFloatSlider seperationW;
    ofxFloatSlider cohesionW;
    ofxFloatSlider alignmentW;
    
    ofxFloatSlider separationThreshold;
    ofxFloatSlider neighbourhoodSize;
    
    ofxFloatSlider maxSpeed;
    ofxFloatSlider maxForce;

    ofxPanel gui;
    
    void seperationWChanged(float & seperationW);
    void cohesionWChanged(float & cohesionW);
    void alignmentWChanged(float & alignmentW);
    void separationThresholdChanged(float &separationThresholdChanged);
    void neighbourhoodSizeChanged(float &neighbourhoodSize);
    void maxSpeedChanged(float &maxSpeed);
    void maxForceChanged(float &maxForce);

};

#endif	
