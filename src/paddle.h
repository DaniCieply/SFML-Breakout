#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

class paddle
{
    private:
        double x;
        double y;
    public:
        sf::RectangleShape paddleShape;
        sf::Vector2f position;
        double height;
        double width;
        paddle(double _x, double _y, double _height, double _width);
        void draw(sf::RenderWindow& window);
        void update(sf::RenderWindow& window);
};