#include <iostream>
#include "paddle.h"

paddle::paddle(double _x, double _y, double _height, double _width)
: paddleShape(sf::Vector2f(width, height)), x(_x), y(_y), height(_height), width(_width)
{
    paddleShape.setFillColor(sf::Color::Red);
    paddleShape.setOrigin(width / 2, height / 2); // Sets origin of paddle to center of itself
    paddleShape.setPosition(x, y); // Sets default starting position
    position = paddleShape.getPosition();  // Updates position vector to default position
    paddleShape.setSize(sf::Vector2f(width, height)); // Workaround because rectangle wasn't drawing
}

void paddle::update(sf::RenderWindow& window)
{
    std::cout << position.x << ", " << position.y << std::endl;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // A key pressed: move paddle left
        paddleShape.move(-5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // A key pressed: move paddle left
        paddleShape.move(5, 0);
    }
    position = paddleShape.getPosition();
}

void paddle::draw(sf::RenderWindow& window)
{
    window.draw(paddleShape);
}
