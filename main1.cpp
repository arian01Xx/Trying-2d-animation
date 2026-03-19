#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

constexpr int TILE=15;

struct World{
    std::vector<std::vector<int>> world={
        50, std::vector<int>(50,0)
    };

    int middle=50/2;

    int row=world.size();
    int col=world[0].size();

    void draw(sf::RenderWindow& window){
        sf::RectangleShape block(sf::Vector2f(TILE, TILE));
        block.setFillColor(sf::Color::Blue);

        sf::VertexArray line1(sf::PrimitiveType::Lines, 2); //cantidad de vertices, en este caso, solo dos
        sf::VertexArray line2(sf::PrimitiveType::Lines, 2);

        line1[0].position={float(TILE*middle), 0.f};
        line1[0].color=sf::Color::Red;
        line1[1].position={float(TILE*middle), float(TILE*row-1)};
        line1[1].color=sf::Color::Green;

        line2[0].position={0.f, float(TILE*middle)};
        line2[0].color=sf::Color::Red;
        line2[1].position={float(TILE*col-1), float(TILE*middle)};
        line2[1].color=sf::Color::Green;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(world[i][j]==0){
                    block.setPosition(sf::Vector2f(j*TILE, i*TILE));
                    window.draw(block);
                }
            }
        }

        window.draw(line1);
        window.draw(line2);
    }
};

struct Functions{
    void firstFunction(World& w, sf::RenderWindow& window){
        for(int x=0; x<w.middle; x++){
            int y=std::pow(x, 2);
            
        }
    }
};

void execute(){
    World w;

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(TILE*w.col), //COLUMNAS 
                static_cast<unsigned>(TILE*w.row)  //FILAS
        }), "GRAPHICS 2D"
    };

    window.setFramerateLimit(60); 

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close(); 
        }

        window.clear();
        w.draw(window);
        window.display();
    }
}


int main(){
    execute();
    return 0;
}
