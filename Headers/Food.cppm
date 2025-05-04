module;

#include <memory>

export module Food;

export class Food
{
protected:
    std::pair<int, int> position_;
    const int size_;

public:
    Food() = delete;
    Food(const Food& food) = delete;
    Food(int xPos, int yPos, const int size);
    virtual ~Food() = default;

    virtual void setPosition(const int xPos, const int yPos);
    virtual std::pair<int, int> getPosition() const {return this->position_;};
    virtual int getRandom(const int upperLimit);
    int getSize() const {return this->size_;};
    void kill();
};
