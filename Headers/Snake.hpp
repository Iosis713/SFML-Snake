#pragma once
#include "Food.hpp"

class Snake : public Food
{
protected:
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };
    Direction direction_ = Direction::Right;
    const int speed_;

public:
    void draw(sf::RenderWindow& i_window);
    Snake(const int speed, const int size);
    void update(const int& width, const int& height);
    void checkIfInsideTheMap(const int& mapWidth, const int& mapHeight);

};

