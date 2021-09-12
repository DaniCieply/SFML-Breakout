#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

class ball 
{
    private:
        double x;
        double y;
        double radius;
        double xSpeed;
        double ySpeed;
        sf::Vector2f position;

        // Collision methods
        bool collidesWith(paddle paddle);
        void checkCollision(paddle paddle);
    public:
        sf::CircleShape ballShape;

        ball(double _x, double _y, double _xSpeed, double _ySpeed,double _size);
        void update(sf::RenderWindow& window, paddle& paddle);
        void draw(sf::RenderWindow& window);
};
