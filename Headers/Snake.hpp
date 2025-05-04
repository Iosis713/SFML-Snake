#pragma once

#include "Food.hpp"
#include "Config.hpp"

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
    Snake() = delete;
    Snake(int xPos, int yPos, const int size, const int speed);
    virtual ~Snake() = default;
    bool checkFoodAndSnakeCollision(Food& food);
    virtual Direction control();
    void draw(sf::RenderWindow& i_window);
    void move();
    size_t getLength() const { return lenght_; };
    Direction getDirection() const { return this->direction_; };
    const std::vector<std::pair<int, int>>& getTailPosition() const {return this->tailPosition_;};
    void update(const Direction newDirection);
    void checkIfInsideTheMap();
    bool isFoodAte(Food& food);
    bool isTailAte();
    void updatePreviousDirection();
};
