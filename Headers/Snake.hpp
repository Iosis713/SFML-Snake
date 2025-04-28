#pragma once

#include "Food.hpp"

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class Snake : public Food
{
protected:
    Direction direction_ = Direction::Right;
    Direction previousDirection_ = Direction::Right;
    const int speed_;
    size_t lenght_ = 4;
    sf::RectangleShape head_;
    std::vector<std::pair<int, int>> tailPosition_;

public:
    bool checkFoodAndSnakeCollision(Food& food);
    virtual Direction control();
    void draw(sf::RenderWindow& i_window);
    Snake(int xPos, int yPos, const int size, const int speed);
    void move();
    size_t getLenght() const { return lenght_; };
    Direction getDirection() const { return this->direction_; };
    void update(const Direction newDirection);
    void checkIfInsideTheMap();
    bool isFoodAte(Food& food);
    bool isTailAte();
    void updatePreviousDirection();
};
