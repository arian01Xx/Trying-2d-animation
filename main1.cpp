#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>
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

struct Opcions{
    std::unordered_map<int, std::function<void()>> functionMap;
    std::unordered_map<int, sf::Text> mapText;

    void init(sf::Font& font){
        sf::Text rotLeft(font, "", 15);
        rotLeft.setFillColor(sf::Color::Black);
        mapText[1]=rotLeft;

        sf::Text rotRight(font, "", 15);
        rotRight.setFillColor(sf::Color::Black);
        mapText[2]=rotRight;

        sf::Text fSquare(font, "", 15);
        fSquare.setFillColor(sf::Color::Black);
        mapText[3]=fSquare;

        sf::Text fSen(font, "", 15);
        fSen.setFillColor(sf::Color::Black);
        mapText[4]=fSen;

        sf::Text fCos(font, "", 15);
        fCos.setFillColor(sf::Color::Black);
        mapText[5]=fCos;

        sf::Text fTan(font, "", 15);
        fTan.setFillColor(sf::Color::Black);
        mapText[6]=fTan;

        sf::Text fCosc(font, "", 15);
        fCosc.setFillColor(sf::Color::Black);
        mapText[7]=fCosc;

        sf::Text fSec(font, "", 15);
        fSec.setFillColor(sf::Color::Black);
        mapText[8]=fSec;

        sf::Text fCot(font, "", 15);
        fCot.setFillColor(sf::Color::Black);
        mapText[9]=fCot;
    }

    void drawingBoxes(sf::RenderWindow& window){
        sf::RectangleShape box1(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box1.setFillColor(sf::Color::Green);
        box1.setPosition(sf::Vector2f(TILE*2, TILE*2));
        window.draw(box1);

        sf::RectangleShape box2(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box2.setFillColor(sf::Color::Blue);
        box2.setPosition(sf::Vector2f(TILE*2, TILE*14));
        window.draw(box2);

        sf::RectangleShape box3(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box3.setFillColor(sf::Color::Yellow);
        box3.setPosition(sf::Vector2f(TILE*2, TILE*26));
        window.draw(box3);

        sf::RectangleShape box4(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box4.setFillColor(sf::Color::Red);
        box4.setPosition(sf::Vector2f(TILE*2, TILE*38));
        window.draw(box4);

        sf::RectangleShape box5(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box5.setFillColor(sf::Color::Cyan);
        box5.setPosition(sf::Vector2f(TILE*2, TILE*50));
        window.draw(box5);

        sf::RectangleShape box6(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box6.setFillColor(sf::Color::White);
        box6.setPosition(sf::Vector2f(TILE*2, TILE*62));
        window.draw(box6);

        sf::RectangleShape box7(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box7.setFillColor(sf::Color::Magenta);
        box7.setPosition(sf::Vector2f(TILE*2, TILE*74));
        window.draw(box7);

        sf::RectangleShape box8(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box8.setFillColor(sf::Color::Green);
        box8.setPosition(sf::Vector2f(TILE*2, TILE*86));
        window.draw(box8);

        sf::RectangleShape box9(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box9.setFillColor(sf::Color::Blue);
        box9.setPosition(sf::Vector2f(TILE*2, TILE*98));
        window.draw(box9);
    }

    /*void rotateLeft(){

    }

    void rotateRight(){

    }

    void funcSquare(){

    }

    void funcSen(){

    }

    void funcCos(){

    }

    void funcTan(){

    }

    void funcCosc(){

    }

    void funcSec(){

    }

    void funcCot(){

    }*/
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
    Opcions o;
    Functions f;

    //f.firstFunction(w);

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(TILE*w.col), //COLUMNAS 
                static_cast<unsigned>(TILE*w.row)  //FILAS
        }), "GRAPHICS 2D"
    };

    window.setFramerateLimit(60);

    //------------------ZONA TEXT--------------------
    sf::Font font;
    if(!font,openFromFile("arial.ttf")) std::cerr<<"No se pudo cargar el archivo\n";

    o.init(font); //este crea los textos que se usaràn
    //-----------------------------------------------

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close(); 
        }

        window.clear();

        w.draw(window); //FONDO PRIMERO
        f.firstFunction(w, window); //CURVA ENCIMA
        o.drawingBoxes(window);

        window.display();
    }
}


int main(){
    execute();
    return 0;
}
