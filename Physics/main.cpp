#include <SFML/Graphics.hpp>
#include "systemState.h"
#include <iostream>

#define WIDTH 1024
#define HEIGHT 1024
const int framerate = 240;

class cBall {
public:
    cBall(float r, float mass) {
        circle.setRadius(r);
        circle.setOrigin(r, r);
        circle.setFillColor(sf::Color::White);
        circle.setPointCount(40);

        systemState.setPosition(circle.getPosition().x, circle.getPosition().y);

        systemState.setMass(mass);
    }

    void setPosition(sf::Vector2f position) {
        circle.setPosition(position);
        systemState.setPosition(circle.getPosition().x, circle.getPosition().y);
    }

    void drawTo(sf::RenderWindow& window) {
        window.draw(circle);
    }

    void update(float deltaTime, int steps) {
        systemState.update(deltaTime, steps);
        circle.setPosition(systemState.getPosition());
    }

    sf::CircleShape circle;
    sSystemState systemState;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "App", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(framerate);

    sf::Clock clock;
    float deltaTime;

    cBall ball(20.0f, 10.0f);
    ball.setPosition(sf::Vector2f(600, HEIGHT / 2));

    ball.systemState.applyForce(500.0f, -10000.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                
            }
        }

        deltaTime = 1 / (float)framerate;

        window.clear();
        ball.drawTo(window);
        ball.update(deltaTime, 20);
        window.display();
    }

    return 0;
}
