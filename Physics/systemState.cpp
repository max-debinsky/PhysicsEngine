#include "systemState.h"
#include <iostream>

const float g = 9.81;
const float G = 6.67 / 10000000;

sSystemState::sSystemState(float _positionX, float _positionY, float _mass) {
	position_x = _positionX;
	position_y = _positionY;

	theta = 0;
	angularVelocity = 0;

	velocity_x = 0;
	velocity_y = 0;

	acceleration_x = 0;
	acceleration_y = 0;

	force_x = 0;
	force_y = 0;

	mass = _mass;
}

void sSystemState::update(float timeStep, int stepSize) {
		applyGravity(g);
		//calculateGravitationalPull(1024.0f, 1024.0f, 100.0f);
		calculateAcceleration();

		velocity_x += acceleration_x * timeStep * stepSize;
		velocity_y += acceleration_y * timeStep * stepSize;

		position_x = position_x + velocity_x * timeStep * stepSize;
		position_y = position_y + velocity_y * timeStep * stepSize;
		
		force_x = 0;
		force_y = 0;
}

void sSystemState::calculateGravitationalPull(float att_x, float att_y, float att_mass) {
	applyForce(-(mass * att_mass) / (att_x - position_x), -(mass * att_mass) / (att_y - position_y));
	std::cout << att_x - position_x << " " << att_y - position_y << std::endl;
}

void sSystemState::applyGravity(float gravity) {
	float force = g * mass;
	applyForce(0.0f, force);
}

void sSystemState::setMass(float _mass) {
	mass = _mass;
}

sf::Vector2f sSystemState::getPosition() {
	return sf::Vector2f(position_x, position_y);
}

sf::Vector2f sSystemState::getVelocity() {
	return sf::Vector2f(velocity_x, velocity_y);
}

void sSystemState::setPosition(float x, float y) {
	position_x = x;
	position_y = y;
}

void sSystemState::calculateAcceleration() {
	acceleration_x = force_x / mass;
	acceleration_y = force_y / mass;
}

void sSystemState::applyForce(float x, float y) {
	force_x += x;
	force_y += y;
}
