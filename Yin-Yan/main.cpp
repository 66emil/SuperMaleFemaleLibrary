#include <SFML/Graphics.hpp>
#include "Grid/Grid.h"
#include <SFML/Window.hpp>

int main()
{
    const int windowWidth = Grid::columns * Grid::cellSize;
    const int windowHeight = Grid::rows * Grid::cellSize;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "In-Yan Game");

    Grid grid;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    grid.handleMouseClick(mousePosition);
                }
            }
        }

        window.clear(sf::Color::White);


        grid.update();
        grid.draw(window);


        window.display();
    }

    return 0;
}
