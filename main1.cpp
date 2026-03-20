#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

constexpr int TILE=5;

struct World{
    std::vector<std::vector<int>> world={
        200, std::vector<int>(200,0)
    };

    int middle=200/2;

    int row=world.size();
    int col=world[0].size();

    void draw(sf::RenderWindow& window){
        sf::RectangleShape block(sf::Vector2f(TILE, TILE));
        block.setFillColor(sf::Color::Black);

        sf::CircleShape circle(float(TILE-1));
        circle.setFillColor(sf::Color::Green);

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
                }/*else if(world[i][j]==1){
                    circle.setPosition(sf::Vector2f(j*TILE, i*TILE));
                    window.draw(circle);
                }*/
            }
        }

        window.draw(line1);
        window.draw(line2);
    }
};

struct Functions{
    void firstFunction(World& w, sf::RenderWindow& window){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        int scale=10;

        //--------ZONA CAMARA-----
        float offsetx=0;
        float offsety=0;
        float zoom=1.0f;
        //------------------------

        for(int x=-w.middle; x<w.middle; x++){
            /*int y=(x*x)/scale;
            
            if(y>=w.middle) continue; //evitar overflow
            
            int gx=x+w.middle;
            int gy=w.middle-y; //invertir eje y
                               
            if(gy>=0 && gy<w.row && gx>=0 && gx<w.col) w.world[gy][gx]=1;*/

            float y=(x*x)/float(scale);

            float px=((x+w.middle)*TILE+offsetx)*zoom;
            float py=((w.middle-y)*TILE+offsety)*zoom;

            //curve.append(sf::Vertex(sf::Vector2f(px, py), sf::Color::Green));
            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
};

void execute(){
    World w;
    Functions f;

    //f.firstFunction(w);

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

        w.draw(window); //FONDO PRIMERO
        f.firstFunction(w, window); //CURVA ENCIMA

        window.display();
    }
}


int main(){
    execute();
    return 0;
}
