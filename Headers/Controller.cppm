module;

#include "Config.hpp"
//#include "Snake.hpp"
import Snake;
#include "SFML/Graphics.hpp"
#include <memory>

export module Controller;

export using SnakePtr = std::shared_ptr<Snake>;

export class Controller
{
private:
    SnakePtr target_ = nullptr;
    
public:
    Controller() = delete;
    Controller(SnakePtr const selectedTarget);
    virtual ~Controller() = default;

    virtual Direction control() const;
};
