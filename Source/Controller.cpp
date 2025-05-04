module;
#include "../Headers/Config.hpp"
#include "SFML/Graphics.hpp"
module Controller; 

Controller::Controller(const SnakePtr selectedTarget)
    : target_(selectedTarget)
{};

Direction Controller::control() const
{
    using enum Direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return Down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return Left;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return Right;
    else
        return target_->getDirection();
}
