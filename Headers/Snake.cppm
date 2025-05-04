module;

//#include "Food.hpp"
import Food;
#include "Config.hpp"
#include <vector>
#include <memory>

export module Snake;

export class Snake : public Food
{
protected:
    Direction direction_ = Direction::Right;
    Direction previousDirection_ = Direction::Right;
    size_t lenght_ = 4;
    std::vector<std::pair<int, int>> tailPosition_;

public:
    Snake() = delete;
    Snake(int xPos, int yPos, const int size);
    virtual ~Snake() = default;
    bool checkFoodAndSnakeCollision(const Food& food) const;
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
