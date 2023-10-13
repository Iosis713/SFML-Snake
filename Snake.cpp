#include "Headers/Snake.hpp"

Snake::Snake(const size_t speed)
    : Food()
    , speed_(speed)
{};

void Snake::draw(sf::RenderWindow& i_window)
{
    sf::RectangleShape rectangle(sf::Vector2f(getSize(), getSize()));
    rectangle.setOrigin(getSize(), getSize());
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(position_.first, position_.second);
    i_window.draw(rectangle);
}
