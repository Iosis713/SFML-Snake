#include <iostream>
//#include <SFML/Graphics.hpp>
#include "Food.hpp"


const int WIDTH = 1024;
const int HEIGHT = 1024;

int main(){
    std::cout << "Hello Snake World\n";
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SSSNAKE!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    Food food;
    

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
        window.draw(shape);
        food.draw(window);     
        window.display();
    }

    return 0;
}

