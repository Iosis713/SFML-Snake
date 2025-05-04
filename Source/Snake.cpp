#include "../Headers/Snake.hpp"
#include <algorithm>
#include <ranges>

Snake::Snake(int xPos, int yPos, const int size)
    : Food(xPos, yPos, size)
{
    tailPosition_.reserve(20);
    for(size_t i = 0; i < lenght_ - 1; i++)
    {
        tailPosition_.push_back(position_);
        tailPosition_[i].first -= static_cast<int>(i) * static_cast<int>(CELL_SIZE);
    }
}

bool Snake::checkFoodAndSnakeCollision(const Food& food) const
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

void Snake::update(const Direction newDirection)
{
    using enum Direction;

    const auto isDirectionUpdated = [&]()
    {
        bool result = false;
        result |= newDirection == Up && previousDirection_ != Down;
        result |= newDirection == Down && previousDirection_ != Up;
        result |= newDirection == Left && previousDirection_ != Right;
        result |= newDirection == Right && previousDirection_ != Left;
        return result;
    };

    if (isDirectionUpdated())
        direction_ = newDirection;
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
    
    using enum Direction;
    switch(direction_)
    {
        case Up:
            position_.second -= CELL_SIZE;
            break;
        case Down:
            position_.second += CELL_SIZE;
            break;
        case Left:
            position_.first -= CELL_SIZE;
            break;
        case Right:
            position_.first += CELL_SIZE;
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
