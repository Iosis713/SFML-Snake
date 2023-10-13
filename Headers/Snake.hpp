#pragma once
#include "Food.hpp"

class Snake : public Food
{
protected:
    const float size_ = 100.0;
    //std::pair<size_t, size_t> position_ {100, 100};
    //
public:
    void draw(sf::RenderWindow& i_window);
    Snake(size_t speed);
    size_t speed_;
};

