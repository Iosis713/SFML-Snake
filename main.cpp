#include "Headers/Food.hpp"
#include "Headers/Snake.hpp"

#include <chrono>
#include <iostream>
#include <thread>

const int CELL_SIZE = 40;
const unsigned FRAME_DURATION = 200;
const int WIDTH = 1280;
const int HEIGHT = 800;

int main(){  
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SNAKE");

    std::string status;
    Food food(20, 140, CELL_SIZE/2);
    Snake snake(60, 180, CELL_SIZE, 1);
    
    //variable for screen refreshing
    std::chrono::time_point<std::chrono::steady_clock> previousTime;
    previousTime = std::chrono::steady_clock::now();
    unsigned deltaTime;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            {
               if (event.type == sf::Event::Closed){
                    window.close();
               }
            }

        window.clear();
        previousTime = std::chrono::steady_clock::now(); 


        do
        {
            snake.update();
            deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousTime).count();   
        }while (FRAME_DURATION > deltaTime);

        snake.isFoodAte(WIDTH, HEIGHT, CELL_SIZE, food);
        food.draw(window);        
        snake.move(WIDTH, HEIGHT, CELL_SIZE);
        snake.draw(window);
       
        window.display();
    }
    return 0;
}

