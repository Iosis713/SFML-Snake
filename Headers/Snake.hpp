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
    Direction previousDirection_ = Direction::Right;
    const int speed_;
    size_t lenght_ = 4;
    sf::RectangleShape head_;
    std::vector<std::pair<int, int>> tailPosition_;

public:
    bool checkFoodAndSnakeCollision(Food& food);
    void draw(sf::RenderWindow& i_window);
    Snake(int xPos, int yPos, const int size, const int speed);
    void move();
    size_t getLenght() const { return lenght_; };
    void update();
    void checkIfInsideTheMap();
    bool isFoodAte(Food& food);
    bool isTailAte();
    void updatePreviousDirection();
};
