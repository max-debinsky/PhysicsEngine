#pragma once
#include <SFML/Graphics.hpp>

struct sSystemState {
public:
	
	sSystemState(float _positionX = 0, float _positionY = 0, float _mass = 1);

	void calculateAcceleration();
	void applyForce(float x, float y);
	void applyGravity(float gravity);
	void calculateGravitationalPull(float att_x, float att_y, float att_mass);
	void update(float deltaTime, int steps);

	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	void setMass(float _mass);
	void setPosition(float x, float y);

private:
	float theta;
	float angularVelocity;

	float position_x, position_y;
	float velocity_x, velocity_y;
	float acceleration_x, acceleration_y;

	float force_x, force_y;

	float mass;
};