#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    std::pair<size_t, size_t> position_;
    bool isAlive = true;
    

public:
    Food() = default;
    ~Food() = default;
    
    
    void draw(sf::RenderWindow& i_window);
    void setIsAlive(bool life);    
    void setPosition(size_t xPos, size_t yPos);
    

    //sf::CircleShape shape_(100);
    //shape_.setFillColor(sf::Color::Red);

    bool getIsAlive();
    std::pair<size_t, size_t> getPosition();
};

