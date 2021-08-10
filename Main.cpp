#include <SFML/Graphics.hpp>
#include "LabirintGen.h"
#include "chovek.h" 

const int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 600;
const int GRID_WIDTH = 38, GRID_HEIGHT = 17;
const int GRID_SIZE_WIDTH = 25, GRID_SIZE_HEIGHT = 25;

int main(){
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "SFML Window", sf::Style::Close | sf::Style::Titlebar);
    sf::CircleShape circle(GRID_SIZE_WIDTH / 5);
    sf::RectangleShape rectangle(sf::Vector2f(GRID_SIZE_WIDTH, GRID_SIZE_HEIGHT));
    sf::Event event;

    mazeGen(GRID_HEIGHT, GRID_WIDTH);

    while(window.isOpen()) {
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        for(int i = 0;i < GRID_HEIGHT;++i){
            for(int x = 0;x < GRID_WIDTH;++x){
                rectangle.setPosition(x * GRID_SIZE_HEIGHT, i * GRID_SIZE_WIDTH);
                if(maze[i][x] == '#'){
                    window.draw(rectangle);
                }
            }
        }
        window.display();
    }
    return 0;
}
