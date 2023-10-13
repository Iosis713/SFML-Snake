#include "Headers/Snake.hpp"

Snake::Snake(const int speed, const int size)
    : Food(size)
    , speed_(speed)
{};

void Snake::draw(sf::RenderWindow& i_window)
{
    sf::RectangleShape rectangle(sf::Vector2f(getSize(), getSize()));
    rectangle.setOrigin(getSize() * 0.5, getSize() * 0.5);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(position_.first, position_.second);
    i_window.draw(rectangle);
}

void Snake::update(const int& width, const int& height)
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

    checkIfInsideTheMap(width, height);

}

void Snake::checkIfInsideTheMap(const int& mapWidth, const int& mapHeight)
{
    if(position_.first > -0.5 * size_ && 
      position_.first < mapWidth + 0.5 * size_ &&
      position_.second > -0.5 * size_ && 
      position_.second < mapHeight + 0.5*size_){}

    else if(position_.first < -0.5 * size_)
    {
        position_.first = mapWidth + 0.5 * size_; //0.5*size so it does not "teleport"
    }
    
    else if(position_.first > mapWidth + 0.5 * size_)
    {
        position_.first = -0.5 * size_;
    }

    else if(position_.second < -0.5 * size_)
    {
        position_.second = mapHeight + 0.5 * size_;
    }

    else if(position_.second > mapHeight + 0.5 * size_)
    {
        position_.second = -0.5 * size_;
    }
}

