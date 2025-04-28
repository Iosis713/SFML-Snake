#include "Headers/Global.hpp"
#include "Headers/Snake.hpp"
#include <algorithm>
#include <ranges>

Snake::Snake(int xPos, int yPos, const int size, const int speed)
    : Food(xPos, yPos, size)
    , speed_(speed)
    , head_(sf::Vector2f(size_ * 0.8, size_ * 0.8))
{
    tailPosition_.reserve(20);
    for(size_t i = 0; i < lenght_ - 1; i++)
    {
        tailPosition_.push_back(position_);
        tailPosition_[i].first -= static_cast<int>(i) * static_cast<int>(CELL_SIZE);
    }
    head_.setOrigin(size_ * 0.4 , size_ * 0.4);
    head_.setFillColor(sf::Color::Blue);
    head_.setOutlineThickness(size_ * 0.2);
    head_.setOutlineColor(sf::Color::Yellow);
};

bool Snake::checkFoodAndSnakeCollision(Food& food)
{
    if (std::ranges::any_of(tailPosition_, [&](const auto& tailElement)
            {
                return (food.getPosition() == tailElement or food.getPosition() == position_);
            }))
    {
        return true;
    }
    return false;
}

bool Snake::isTailAte()
{   
    if (std::ranges::any_of(tailPosition_, [&](const auto& tailElement)
            {
                return tailElement == position_;
            }))
    {
        return true;
    }
    return false;
}

void Snake::draw(sf::RenderWindow& i_window)
{
    head_.setPosition(position_.first, position_.second);
    
    i_window.draw(head_);

    for(auto element : tailPosition_)
    {
        sf::RectangleShape rectangleTail(sf::Vector2f(size_*0.8 , size_*0.8));
        rectangleTail.setOrigin(size_ * 0.4 , size_ * 0.4);
        rectangleTail.setFillColor(sf::Color::Green);
        rectangleTail.setPosition(element.first, element.second);
        i_window.draw(rectangleTail);
    }
}

void Snake::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                                  && previousDirection_ != Direction::Down)
    {
        direction_ = Direction::Up;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                                        && previousDirection_ != Direction::Up)
    {
        direction_ = Direction::Down;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                                        && previousDirection_ != Direction::Right)
    {
        direction_ = Direction::Left;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                                        && previousDirection_ != Direction::Left)
    {
        direction_ = Direction::Right;
    }
}

void Snake::updatePreviousDirection()
{
    previousDirection_ = direction_;
}

void Snake::move()
{
    std::vector<std::pair<int, int>> temporary;
    temporary.reserve(tailPosition_.capacity());
    temporary = tailPosition_;
    tailPosition_[0] = position_;
    
    switch(direction_)
    {
        case Direction::Up:
            position_.second -= speed_ * CELL_SIZE;
            break;

        case Direction::Down:
            position_.second += speed_ * CELL_SIZE;
            break;

        case Direction::Left:
            position_.first -= speed_ * CELL_SIZE;
            break;

        case Direction::Right:
            position_.first += speed_ * CELL_SIZE;
            break;
    }
   
    for(size_t i = 1; i < lenght_; i++)
    {
        tailPosition_[i] = temporary[i-1];
    }

    checkIfInsideTheMap();
}

void Snake::checkIfInsideTheMap()
{
    if(position_.first > 0.5 * size_ && 
      position_.first < WIDTH - 0.5 * size_ &&
      position_.second > +0.5 * size_ && 
      position_.second < HEIGHT - 0.5 * size_){}

    else if(position_.first < 0.5 * size_)
    {
        position_.first = WIDTH - 0.5 * size_; //0.5*size so it does not "teleport"
    }
    
    else if(position_.first > WIDTH - 0.5 * size_)
    {
        position_.first = 0.5 * size_;
    }

    else if(position_.second < 0.5 * size_)
    {
        position_.second = HEIGHT - 0.5 * size_;
    }

    else if(position_.second > HEIGHT - 0.5 * size_)
    {
        position_.second = 0.5 * size_;
    }
}

bool Snake::isFoodAte(Food& food)
{
    if(getPosition() == food.getPosition())
    {
        lenght_++;
        std::vector<std::pair<int, int>> temporary;
        temporary.reserve(tailPosition_.capacity() + 1);
        temporary = tailPosition_;
        tailPosition_.push_back(*temporary.end());
        food.kill();
        
        while(checkFoodAndSnakeCollision(food))
        {
            food.kill();
        }
        return true;
    }
    else
        return false;
}
