#include <iostream>
#include <cmath>
#include "ball.h"

ball::ball(double _x, double _y, double _xSpeed, double _ySpeed,double _radius) 
: ballShape(radius), x(_x), y(_y), xSpeed(_xSpeed), ySpeed(_ySpeed), radius(_radius) // Memeber initializer list
{
    ballShape.setFillColor(sf::Color::White);
    ballShape.setOrigin(radius, radius); // Sets origin of ball to center of itself
    ballShape.setPosition(x, y); // Sets default starting position
    position = ballShape.getPosition();  // Updates position vector to default position
}

void ball::update(sf::RenderWindow& window, paddle& paddle) // Runs once per frame
{
    position = ballShape.getPosition(); // Updates position vector to current position

    if (position.x < radius || position.x > window.getSize().x - radius) // If the ball tries to go beyond the screen borders, reverse speed
    {
       xSpeed = -xSpeed;
    } 

    if (position.y < radius || position.y > window.getSize().y - radius) // If the ball tries to go beyond the screen borders, reverse speed
    {
       ySpeed = -ySpeed;
    } 
    checkCollision(paddle);
    ballShape.move(xSpeed, ySpeed);
}

void ball::draw(sf::RenderWindow& window)
{
    window.draw(ballShape);
}

bool ball::collidesWith(paddle paddle) // Calculates paddle and ball collision
{
    double distanceXCBAP;
    double distanceYCBAP;
    double distanceXBAP;
    double distanceYBAP;

    // Distance between paddle and ball
    distanceXCBAP = abs((paddle.position.x + (paddle.width / 2)) - position.x);
    distanceYCBAP = abs((paddle.position.y + (paddle.height / 2)) - position.y);
    distanceXBAP = radius + (paddle.width / 2);
    distanceYBAP = radius + (paddle.height / 2);

    return distanceXCBAP <= distanceXBAP && distanceYCBAP <= distanceYBAP;
}

void ball::checkCollision(paddle paddle) // Checks for collision with the paddle
{ 
    if (collidesWith(paddle)) 
    {
        ySpeed = -ySpeed;
    }
}