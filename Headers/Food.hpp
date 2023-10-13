#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    std::pair<size_t, size_t> position_;
    bool isAlive_ = true;
    const float size_ = 50;
    //sf::CircleShape circle2;

public:
    Food();
    ~Food() = default;

    void draw(sf::RenderWindow& i_window);
    void setIsAlive(bool life);    
    void setPosition(const size_t& xPos,const size_t& yPos);
    float getSize();    

    void kill();
    bool getIsAlive();
    std::pair<size_t, size_t> getPosition();
};

