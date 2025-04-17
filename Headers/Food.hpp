#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    std::pair<int, int> position_;
    const int size_;

public:
    Food() = delete;
    Food(const int size, int xPos, int yPos);
    ~Food() = default;

    void draw(sf::RenderWindow& i_window); 
    virtual void setPosition(const int& xPos,const int& yPos);
    std::pair<int, int> getPosition();
    virtual int getRandom(const int upperLimit);
    float getSize();    

    void kill();
};

