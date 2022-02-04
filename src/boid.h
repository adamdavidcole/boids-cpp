/*

 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"
//#include "flock.hpp"
class Flock;

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
public:
	ofVec3f position;
	ofVec3f velocity;
    ofVec3f acceleration;
    
    float maxForce;
    float maxSpeed;
	
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
	
	float separationThreshold;
	float neighbourhoodSize;
	
	virtual ofVec3f separation(std::vector<Boid *> &otherBoids);
	ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);
    
    ofColor color;

// all the methods and variables after the
// public keyword can only be used by anyone
	Boid(ofColor color);
	Boid(ofVec3f &pos, ofVec3f &vel, ofColor color);
	
	~Boid();
    
    
    static constexpr float INITIAL_SEPARATION_WEIGHT = 0.85;
    static constexpr float INITIAL_COHESION_WEIGHT = 0.75;
    static constexpr float INITIAL_ALIGHNMENT_WEIGHT = 0.5;
    static constexpr float INITIAL_SEPARATION_THRESHOLD = 50;
    static constexpr float INITIAL_NEIGHBORHOOD_SIZE = 100;
    static constexpr float INITIAL_MAX_FORCE = 1;
    static constexpr float INITIAL_MAX_SPEED = 2.5;
	
	ofVec3f getPosition();
	ofVec3f getVelocity();
    ofVec3f getAcceleration();
    	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
    
    void setMaxSpeed(float f);
    void setMaxForce(float f);
    
    void setColor(ofColor color);
	
	void update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max);
    void update(std::vector<Flock *> &otherFlocks, ofVec3f &min, ofVec3f &max);

	
	void walls(ofVec3f &min, ofVec3f &max);
	
	virtual void draw();
};

#endif
