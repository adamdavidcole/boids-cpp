//
//  shark.cpp
//  boids
//
//  Created by Adam Cole on 2/3/22.
//

#include "shark.hpp"

Shark::Shark(ofColor color) : Boid(color) {
//    static constexpr float INITIAL_SEPARATION_WEIGHT = 2.0;
//    static constexpr float INITIAL_COHESION_WEIGHT = 0.75;
//    static constexpr float INITIAL_ALIGHNMENT_WEIGHT = 0.5;
//    static constexpr float INITIAL_SEPARATION_THRESHOLD = 100;
//    static constexpr float INITIAL_NEIGHBORHOOD_SIZE = 50;
//    static constexpr float INITIAL_MAX_FORCE = 2;
//    static constexpr float INITIAL_MAX_SPEED = 1;
    
    separationWeight = Shark::INITIAL_SEPARATION_WEIGHT;
    cohesionWeight = Shark::INITIAL_COHESION_WEIGHT;
    alignmentWeight = Shark::INITIAL_ALIGHNMENT_WEIGHT;
    separationThreshold = Shark::INITIAL_SEPARATION_THRESHOLD;
    neighbourhoodSize = Shark::INITIAL_NEIGHBORHOOD_SIZE;
    maxForce = Shark::INITIAL_MAX_FORCE;
    maxSpeed = 1;
    
    cout << this->maxSpeed << endl;

}

void Shark::draw() {
    ofSetColor(color);

    ofVec3f pos = getPosition();
    
    ofPushMatrix();
    ofTranslate(pos);
    ofDrawCircle(0, 0, size);
    ofPopMatrix();
}

ofVec3f Shark::fishCohesion(std::vector<Boid *> &otherBoids) {
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        Boid* otherBoid = otherBoids[i];
        ofVec3f otherBoidPosition = otherBoid->getPosition();
        float d = position.distance(otherBoidPosition);

        if ((d > 0) && (d < neighbourhoodSize/2.0))
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

void Shark::update(std::vector<Boid *> &otherBoids, std::vector<Boid*> &fish, ofVec3f &min, ofVec3f &max) {
    acceleration += separationWeight*separation(otherBoids);
    acceleration += cohesionWeight*cohesion(otherBoids);
    acceleration += alignmentWeight*alignment(otherBoids);
    
    acceleration += fishCohesion(fish);

    velocity += acceleration;
    velocity.limit(maxSpeed);
    position += velocity;
    acceleration *= 0.0;
    
    walls(min, max);
    
    
    cout << maxSpeed << endl;

}
