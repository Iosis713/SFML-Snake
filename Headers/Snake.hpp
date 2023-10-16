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
    Snake(int xPos, int yPos, const int size, const int speed);
    void move(const int& width, const int& height, const int& cellSize);
    size_t getLenght();
    void update();
    void checkIfInsideTheMap(const int& mapWidth, const int& mapHeight);
    bool isFoodAte(const int& mapWidth, const int& mapHeight, const int& cellSize, Food& food);

};

