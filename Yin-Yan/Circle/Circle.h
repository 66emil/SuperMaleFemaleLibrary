#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>

class Circle
{
public:
    enum class ColorState
    {
        None,
        Black,
        White
    };
    Circle();

    void setPosition(sf::Vector2f position);
    void setFillColor(sf::Color color);
    void setExists(bool exists);
    bool exists() const;
    void draw(sf::RenderWindow& window);
    void toggleColor();
    sf::Color getColor() const;
    void setColorState(ColorState state);
    ColorState getColorState() const;

private:
    sf::CircleShape m_circle;
    bool m_exists;
    sf::Color m_fillColor;
    ColorState m_colorState;
};

#endif // CIRCLE_H
