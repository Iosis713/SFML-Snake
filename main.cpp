#include "Headers/Food.hpp"
#include "Headers/Snake.hpp"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

const int CELL_SIZE = 40;
const unsigned FRAME_DURATION = 200;
const int WIDTH = 1280;
const int HEIGHT = 800;


int getRandom(const int& lowerLimit, const int& upperLimit);
auto refresh = [](){using namespace std::chrono_literals;
                      std::this_thread::sleep_for(100ms);};

int main(){  
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SNAKE");

    std::string status;
    Food food(CELL_SIZE/2);
    Snake snake(1, CELL_SIZE);
    
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
        //    std::cout << "dt = " << deltaTime << '\n';
        }while (FRAME_DURATION > deltaTime);

        food.draw(window);        
        snake.move(WIDTH, HEIGHT, CELL_SIZE);
        snake.draw(window);
        window.display();
        
        
        //std::cout << "Snake (x, y) = (" << snake.getPosition().first << ", "
        //         << snake.getPosition().second << ")\n";
        

        //refresh();  
    }

    return 0;
}

/*************************************************************************************/

int getRandom(const int& lowerLimit, const int& upperLimit)
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> dist((int) lowerLimit, upperLimit);
    return dist(randGenerator);
}

