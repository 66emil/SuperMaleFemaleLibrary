#include "Circle.h"

Circle::Circle()
{
    m_circle.setRadius(25.f);
    m_circle.setOrigin(25.f, 25.f);
    m_exists = false;
}

void Circle::setPosition(sf::Vector2f position)
{
    m_circle.setPosition(position);
}


void Circle::setFillColor(sf::Color color)
{
    m_fillColor = color;

    // Set the outline color to black for white circles
    if (color == sf::Color::White)
    {
        m_circle.setOutlineColor(sf::Color::Black);
    }
    else
    {
        m_circle.setOutlineColor(sf::Color::Transparent);
    }
}
void Circle::toggleColor()
{
    if (m_fillColor == sf::Color::Black)
    {
        m_fillColor = sf::Color::White;
    }
    else if (m_fillColor == sf::Color::White)
    {
        m_fillColor = sf::Color::Transparent;
    }
    else
    {
        m_fillColor = sf::Color::Black;
    }
}

void Circle::setExists(bool exists)
{
    m_exists = exists;
}

bool Circle::exists() const
{
    return m_exists;
}
void Circle::setColorState(ColorState state)
{
    m_colorState = state;
}
sf::Color Circle::getColor() const
{
    return m_fillColor;
}

Circle::ColorState Circle::getColorState() const
{
    if (m_fillColor == sf::Color::Black)
    {
        return ColorState::Black;
    }
    else if (m_fillColor == sf::Color::White)
    {
        return ColorState::White;
    }
    else
    {
        return ColorState::None;
    }
}

void Circle::draw(sf::RenderWindow& window)
{
    if (m_exists)
    {
        if (m_colorState == ColorState::Black) // Добавлена проверка состояния цвета для установки оправы
        {
            m_circle.setOutlineColor(sf::Color::Black);
        }
        else if (m_colorState == ColorState::White)
        {
            m_circle.setOutlineColor(sf::Color::White);
        }
        else
        {
            m_circle.setOutlineColor(sf::Color::Transparent);
        }

        window.draw(m_circle);
    }
}

