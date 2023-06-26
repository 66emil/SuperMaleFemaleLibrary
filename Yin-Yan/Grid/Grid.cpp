#include "Grid.h"

const int Grid::rows = 6;
const int Grid::columns = 6;
const float Grid::cellSize = 100.f;

Grid::Grid()
{
    m_circles.resize(rows, std::vector<Circle>(columns));

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            m_circles[row][col].setExists(false);
            m_circles[row][col].setFillColor(sf::Color::Black); // Устанавливаем цвет оправы в черный для всех кругов
        }
    }
}

void Grid::draw(sf::RenderWindow& window)
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            if (m_circles[row][col].exists())
            {
                float xPos = col * cellSize + cellSize / 2.f;
                float yPos = row * cellSize + cellSize / 2.f;

                m_circles[row][col].setPosition(sf::Vector2f(xPos, yPos));
                m_circles[row][col].draw(window);
            }

            sf::Vertex line[] =
                    {
                            sf::Vertex(sf::Vector2f(col * cellSize, row * cellSize), sf::Color::Black),
                            sf::Vertex(sf::Vector2f(col * cellSize, (row + 1) * cellSize), sf::Color::Black)
                    };
            window.draw(line, 2, sf::Lines);

            line[0] = sf::Vertex(sf::Vector2f(col * cellSize, row * cellSize), sf::Color::Black);
            line[1] = sf::Vertex(sf::Vector2f((col + 1) * cellSize, row * cellSize), sf::Color::Black);
            window.draw(line, 2, sf::Lines);
        }
    }
}

void Grid::handleMouseClick(const sf::Vector2f& mousePosition)
{
    int col = static_cast<int>(mousePosition.x / cellSize);
    int row = static_cast<int>(mousePosition.y / cellSize);

    if (row >= 0 && row < rows && col >= 0 && col < columns)
    {
        m_circles[row][col].toggleColor();
        m_circles[row][col].setColorState(m_circles[row][col].getColorState()); // Добавлена установка состояния цвета
        m_circles[row][col].setExists(true);

    }
}


void Grid::update()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            Circle& circle = m_circles[row][col];
            if (circle.getColorState() == Circle::ColorState::Black)
            {
                circle.setFillColor(sf::Color::Black);
            }
            else if (circle.getColorState() == Circle::ColorState::White)
            {
                circle.setFillColor(sf::Color::White);
            }
            else
            {
                circle.setFillColor(sf::Color::Transparent);
            }
        }
    }
}

