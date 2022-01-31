/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"

Boid::Boid()
{
	separationWeight = INITIAL_SEPARATION_WEIGHT;
	cohesionWeight = INITIAL_COHESION_WEIGHT;
	alignmentWeight = INITIAL_ALIGHNMENT_WEIGHT;
	
	separationThreshold = INITIAL_SEPARATION_THRESHOLD;
	neighbourhoodSize = INITIAL_NEIGHBORHOOD_SIZE;
	
	position = ofVec3f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
    acceleration = ofVec3f();
    
    maxSpeed = INITIAL_MAX_SPEED;
    maxForce = INITIAL_MAX_FORCE;
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
    separationWeight = INITIAL_SEPARATION_WEIGHT;
    cohesionWeight = INITIAL_COHESION_WEIGHT;
    alignmentWeight = INITIAL_ALIGHNMENT_WEIGHT;
	
	separationThreshold = INITIAL_SEPARATION_THRESHOLD;
	neighbourhoodSize = INITIAL_NEIGHBORHOOD_SIZE;
	
	position = pos;
	velocity = vel;
    acceleration = ofVec3f();
    
    maxSpeed = INITIAL_MAX_SPEED;
    maxForce = INITIAL_MAX_FORCE;
}

Boid::~Boid()
{
	
}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}

void Boid::setMaxSpeed(float f)
{
    maxSpeed = f;
}
void Boid::setMaxForce(float f)
{
    maxForce = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
    ofVec3f steer;
    int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);
            
        
        if ((d > 0) && (d < separationThreshold)) {
            ofVec3f diff = position - otherBoidPosition;
//            diff.normalize();
            diff /= d;
            steer += diff;
            count = count + 1;
        }
	}
    
    if (count > 0) {
        steer /= ((float) count);
    }
    
    if (steer.lengthSquared() > 0) {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }
    
    return steer;
}

//ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
//{
//	ofVec3f average(0,0,0);
//	int count = 0;
//	for (int i = 0; i < otherBoids.size(); i++)
//	{
//		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
//		{
//			average += otherBoids[i]->getPosition();
//			count += 1;
//		}
//	}
//	average /= count;
//	ofVec3f v =  average - position;
//	v.normalize();
//	return v;
//}
ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);

        if ((d > 0) && (d < neighbourhoodSize))
        {
            average += otherBoid->getPosition();
            count += 1;
        }
    }
    if (count > 0) {
        average /= ((float)count);
        average -= position;
        average.normalize();
        average *= maxSpeed;
        ofVec3f steer = average - velocity;
        steer.limit(maxForce);
        return steer;
    }
    
    return ofVec3f();
}

ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);

		if ((d > 0) && (d < neighbourhoodSize))
		{
			average += otherBoid->getVelocity();
			count += 1;
		}
	}
    if (count > 0) {
        average /= ((float)count);
        average.normalize();
        average *= maxSpeed;
        ofVec3f steer =  average - velocity;
        steer.limit(maxForce);
        return steer;
    }
    
    return ofVec3f();
}

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
	acceleration += separationWeight*separation(otherBoids);
    acceleration += cohesionWeight*cohesion(otherBoids);
    acceleration += alignmentWeight*alignment(otherBoids);

    velocity += acceleration;
    velocity.limit(maxSpeed);
	position += velocity;
    acceleration *= 0.0;
    
    walls(min, max);
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
//	if (position.x < min.x){
//		position.x = min.x;
//		velocity.x *= -1;
//	} else if (position.x > max.x){
//		position.x = max.x;
//		velocity.x *= -1;
//	}
//
//	if (position.y < min.y){
//		position.y = min.y;
//		velocity.y *= -1;
//	} else if (position.y > max.y){
//		position.y = max.y;
//		velocity.y *= -1;
//	}
    if (position.x < min.x){
        position.x = max.x;
    } else if (position.x > max.x){
        position.x = min.x;
    }
    if (position.y < min.y){
        position.y = max.y;
    } else if (position.y > max.y){
        position.y = min.y;
    }
	
	
}

void Boid::draw()
{
	ofSetColor(0, 255, 255);
	ofCircle(position.x, position.y, 5);
}
