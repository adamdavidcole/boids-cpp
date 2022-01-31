/*

 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:	
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
	
	ofVec3f separation(std::vector<Boid *> &otherBoids);
	ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);
	
// all the methods and variables after the
// public keyword can only be used by anyone
public:	
	Boid();
	Boid(ofVec3f &pos, ofVec3f &vel);
	
	~Boid();
    
    
    static constexpr float INITIAL_SEPARATION_WEIGHT = 0.85;
    static constexpr float INITIAL_COHESION_WEIGHT = 0.75;
    static constexpr float INITIAL_ALIGHNMENT_WEIGHT = 0.5;
    static constexpr float INITIAL_SEPARATION_THRESHOLD = 50;
    static constexpr float INITIAL_NEIGHBORHOOD_SIZE = 100;
    static constexpr float INITIAL_MAX_FORCE = 1;
    static constexpr float INITIAL_MAX_SPEED = 5;
	
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
	
	void update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max);
	
	void walls(ofVec3f &min, ofVec3f &max);
	
	void draw();
};

#endif
