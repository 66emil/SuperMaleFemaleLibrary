#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Circle/Circle.h"

class Grid
{
public:
    Grid();
    static const int rows;
    void update();
    static const int columns;
    static const float cellSize;
    void draw(sf::RenderWindow& window);
    void handleMouseClick(const sf::Vector2f& mousePosition);

private:


    std::vector<std::vector<Circle>> m_circles;

    // Метод для проверки, является ли группа кружков размером 2х2 или более
    bool isGroupOfSizeTwoOrMore(int row, int col) const;
};

