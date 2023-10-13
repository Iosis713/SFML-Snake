#pragma once
#include "Food.hpp"

class Snake : public Food
{
protected:
    const float size_ = 100.0;
    //std::pair<size_t, size_t> position_ {100, 100};
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };
    Direction direction_ = Direction::Right;

public:
    void draw(sf::RenderWindow& i_window);
    Snake(const size_t speed);
    const size_t speed_;
    void update();
};

