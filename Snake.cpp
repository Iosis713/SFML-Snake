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

void Snake::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        direction_ = Direction::Up;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        direction_ = Direction::Down;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        direction_ = Direction::Left;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        direction_ = Direction::Right;
    }

    switch(direction_)
    {
        case Direction::Up:
            position_.second -= speed_;
            break;

        case Direction::Down:
            position_.second += speed_;
            break;

        case Direction::Left:
            position_.first -= speed_;
            break;

        case Direction::Right:
            position_.first += speed_;
            break;
    }

}
