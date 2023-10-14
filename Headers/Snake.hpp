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
    size_t lenght_ = 3;

public:
    void draw(sf::RenderWindow& i_window);
    Snake(const int speed, const int size);
    void move(const int& width, const int& height, const int& cellSize);
    void update();
    void checkIfInsideTheMap(const int& mapWidth, const int& mapHeight);

};

