#pragma once

#include "Config.hpp"
#include "Snake.hpp"
#include "SFML/Graphics.hpp"
#include <memory>

using SnakePtr = std::shared_ptr<Snake>;

class Controller
{
private:
    SnakePtr target_ = nullptr;
    
public:
    Controller() = delete;
    Controller(SnakePtr const selectedTarget);
    virtual ~Controller() = default;

    virtual Direction control() const;
};
