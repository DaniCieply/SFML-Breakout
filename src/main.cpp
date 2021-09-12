#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"

// TODO: Figure out why paddle stopped rendering

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Breakout", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    paddle paddle(320, 400, 10, 60);
    ball ball(320, 240, 2, 2, 10);

    while (window.isOpen()) // Main game loop
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        paddle.update(window);
        paddle.draw(window);
        ball.update(window, paddle);
        ball.draw(window);
        window.display();
    }

    return 0;
}
