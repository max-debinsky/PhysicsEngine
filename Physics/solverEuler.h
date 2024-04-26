#pragma once

void solveEuler(float& position_x, float& position_y, float velocity_x, float velocity_y, float timeStep) {
	position_x = position_x + velocity_x * timeStep;
	position_y = position_y + velocity_y * timeStep;
}