#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

constexpr int TILE=5;

struct BOXES{
    std::pair<int,int> position;
    int weight;
    int height;
    int value1=10;
    int value2=20;
};

struct World{
    std::vector<std::vector<int>> world={
        200, std::vector<int>(200,0)
    };

    int middle=200/2;

    int row=world.size();
    int col=world[0].size();

    std::vector<BOXES> boxes;

    enum FUNCTION{ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    FUNCTION fun=THREE;

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
    //std::unordered_map<int, sf::Text> mapText;
    std::vector<sf::Text> texts;

    void init(sf::Font& font){
        sf::Text rotLeft(font, "", 15);
        rotLeft.setFillColor(sf::Color::Black);
        //mapText[1]=rotLeft;
        texts.push_back(rotLeft);

        sf::Text rotRight(font, "", 15);
        rotRight.setFillColor(sf::Color::Black);
        //mapText[2]=rotRight;
        texts.push_back(rotRight);

        sf::Text fSquare(font, "", 15);
        fSquare.setFillColor(sf::Color::Black);
        //mapText[3]=fSquare;
        texts.push_back(fSquare);

        sf::Text fSen(font, "", 15);
        fSen.setFillColor(sf::Color::Black);
        //mapText[4]=fSen;
        texts.push_back(fSen);

        sf::Text fCos(font, "", 15);
        fCos.setFillColor(sf::Color::Black);
        //mapText[5]=fCos;
        texts.push_back(fCos);

        sf::Text fTan(font, "", 15);
        fTan.setFillColor(sf::Color::Black);
        //mapText[6]=fTan;
        texts.push_back(fTan);

        sf::Text fCosc(font, "", 15);
        fCosc.setFillColor(sf::Color::Black);
        //mapText[7]=fCosc;
        texts.push_back(fCosc);

        sf::Text fSec(font, "", 15);
        fSec.setFillColor(sf::Color::Black);
        //mapText[8]=fSec;
        texts.push_back(fSec);

        sf::Text fCot(font, "", 15);
        fCot.setFillColor(sf::Color::Black);
        //mapText[9]=fCot;
        texts.push_back(fCot);
    }

    void drawingBoxes(World& w, sf::RenderWindow& window){
        sf::RectangleShape box1(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box1.setFillColor(sf::Color::Green);
        box1.setPosition(sf::Vector2f(TILE*2, TILE*2));
        window.draw(box1);

        BOXES Box1;
        Box1.position={TILE*2, TILE*2};
        Box1.weight=TILE*20;
        Box1.height=TILE*10;
         w.boxes.push_back(Box1);
        
        texts[0].setString("Rotate to\n the Left");
        texts[0].setPosition(sf::Vector2f(TILE*3, TILE*3));
        window.draw(texts[0]); 

        sf::RectangleShape box2(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box2.setFillColor(sf::Color::Blue);
        box2.setPosition(sf::Vector2f(TILE*2, TILE*14));
        window.draw(box2);

        BOXES Box2;
        Box2.position={TILE*2, TILE*14};
        Box2.weight=TILE*20;
        Box2.height=TILE*10;
        w.boxes.push_back(Box2);

        texts[1].setString("Rotate to\n the Right");
        texts[1].setPosition(sf::Vector2f(TILE*3, TILE*15));
        window.draw(texts[1]); 

        sf::RectangleShape box3(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box3.setFillColor(sf::Color::Yellow);
        box3.setPosition(sf::Vector2f(TILE*2, TILE*26));
        window.draw(box3);

        BOXES Box3;
        Box3.position={TILE*2, TILE*26};
        Box3.weight=TILE*20;
        Box3.height=TILE*10;
        w.boxes.push_back(Box3);

        texts[2].setString("f(x)=y=x^2");
        texts[2].setPosition(sf::Vector2f(TILE*3, TILE*27));
        window.draw(texts[2]);

        sf::RectangleShape box4(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box4.setFillColor(sf::Color::Red);
        box4.setPosition(sf::Vector2f(TILE*2, TILE*38));
        window.draw(box4);

        BOXES Box4;
        Box4.position={TILE*2, TILE*38};
        Box4.weight=TILE*20;
        Box4.height=TILE*10;
        w.boxes.push_back(Box4);

        texts[3].setString("f(x)=y=sen(x)");
        texts[3].setPosition(sf::Vector2f(TILE*3, TILE*39));
        window.draw(texts[3]); 

        sf::RectangleShape box5(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box5.setFillColor(sf::Color::Cyan);
        box5.setPosition(sf::Vector2f(TILE*2, TILE*50));
        window.draw(box5);

        BOXES Box5;
        Box5.position={TILE*2, TILE*50};
        Box5.weight=TILE*20;
        Box5.height=TILE*10;
        w.boxes.push_back(Box5);

        texts[4].setString("f(x)=y=cos(x)");
        texts[4].setPosition(sf::Vector2f(TILE*3, TILE*51));
        window.draw(texts[4]);

        sf::RectangleShape box6(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box6.setFillColor(sf::Color::White);
        box6.setPosition(sf::Vector2f(TILE*2, TILE*62));
        window.draw(box6);

        BOXES Box6;
        Box6.position={TILE*2, TILE*62};
        Box6.weight=TILE*20;
        Box6.height=TILE*10;
        w.boxes.push_back(Box6);

        texts[5].setString("f(x)=y=tan(x)");
        texts[5].setPosition(sf::Vector2f(TILE*3, TILE*63));
        window.draw(texts[5]);

        sf::RectangleShape box7(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box7.setFillColor(sf::Color::Magenta);
        box7.setPosition(sf::Vector2f(TILE*2, TILE*74));
        window.draw(box7);

        BOXES Box7;
        Box7.position={TILE*2, TILE*74};
        Box7.weight=TILE*20;
        Box7.height=TILE*10;
        w.boxes.push_back(Box7);

        texts[6].setString("f(x)=y=cosc(x)");
        texts[6].setPosition(sf::Vector2f(TILE*3, TILE*75));
        window.draw(texts[6]);

        sf::RectangleShape box8(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box8.setFillColor(sf::Color::Green);
        box8.setPosition(sf::Vector2f(TILE*2, TILE*86));
        window.draw(box8);

        BOXES Box8;
        Box8.position={TILE*2, TILE*86};
        Box8.weight=TILE*20;
        Box8.height=TILE*10;
        w.boxes.push_back(Box8);

        texts[7].setString("f(x)=y=sec(x)");
        texts[7].setPosition(sf::Vector2f(TILE*3, TILE*87));
        window.draw(texts[7]);

        sf::RectangleShape box9(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box9.setFillColor(sf::Color::Blue);
        box9.setPosition(sf::Vector2f(TILE*2, TILE*98));
        window.draw(box9);

        BOXES Box9;
        Box9.position={TILE*2, TILE*98};
        Box9.weight=TILE*20;
        Box9.height=TILE*10;
        w.boxes.push_back(Box9);

        texts[8].setString("f(x)=y=cot(x)");
        texts[8].setPosition(sf::Vector2f(TILE*3, TILE*99));
        window.draw(texts[8]);
    }

    /*
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

struct Camera{
    float offsetx=0;
    float offsety=0;
    float zoom=1.0f;
};

struct Functions{
    void selection(World& w, sf::RenderWindow& window, Camera& cam){
        if(w.fun==w.FUNCTION::ONE) rotateLeft(w, window);
        if(w.fun==w.FUNCTION::TWO) rotateRight(w, window);
        if(w.fun==w.FUNCTION::THREE) funcSquare(w, window, cam);
    }

    void rotateLeft(World& w, sf::RenderWindow& window){

    }

    void rotateRight(World& w, sf::RenderWindow& window){

    }

    void funcSquare(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        int scale=10; 

        for(int x=-w.middle; x<w.middle; x++){
            /*int y=(x*x)/scale;
            
            if(y>=w.middle) continue; //evitar overflow
            
            int gx=x+w.middle;
            int gy=w.middle-y; //invertir eje y
                               
            if(gy>=0 && gy<w.row && gx>=0 && gx<w.col) w.world[gy][gx]=1;*/

            float y=(x*x)/float(scale);

            float px=((x+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            //curve.append(sf::Vertex(sf::Vector2f(px, py), sf::Color::Green));
            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
};

bool verify(BOXES& box, int& row, int& col){
    if(row>=box.position.second && row<((box.position.second/TILE)+box.value1)*TILE &&
       col>=box.position.first && col<((box.position.first/TILE)+box.value2)*TILE){
        std::cout<<"ROW: "<<row<<", box.position.second: "<<box.position.second<<std::endl;
        std::cout<<"COL: "<<col<<", box.position.first: "<<box.position.first<<std::endl;
        return true;
    }
    return false;
}

void drawAxisNumbers(sf::RenderWindow& window, World& w, Camera& cam, sf::Font& font){
    int width = window.getSize().x;

    float originX = (w.middle * TILE) * cam.zoom;
    float axisY   = (w.middle * TILE) * cam.zoom;

    for(int px = 0; px < width; px += 60){
        // distancia desde el origen
        int worldX = (px - originX) / cam.zoom / TILE;

        sf::Text text(font, "", 12);
        text.setFillColor(sf::Color::White);

        text.setString(std::to_string(worldX).substr(0,5));

        text.setPosition(sf::Vector2f(px, axisY));

        window.draw(text);
    }
}

Camera handleInput(Camera& cam){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) cam.offsetx-=5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) cam.offsetx+=5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) cam.offsety-=5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) cam.offsety+=5;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) cam.zoom*=1.01f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) cam.zoom*=0.99f;

    return cam;
}

void execute(){
    World w;
    Opcions o;
    Camera cam;
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
    if(!font.openFromFile("arial.ttf")) std::cerr<<"No se pudo cargar el archivo\n";

    o.init(font); //este crea los textos que se usaràn
    //-----------------------------------------------

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close();
            if(const auto* mouseButtonPressed=event->getIf<sf::Event::MouseButtonPressed>()){
                int col=mouseButtonPressed->position.x/TILE;
                int row=mouseButtonPressed->position.y/TILE;

                std::cout<<"COL MOUSE: "<<col<<std::endl;
                std::cout<<"ROW MOUSE: "<<row<<std::endl;
                
                //TIENE QUE SER CAJA POR CAJA
                if(verify(w.boxes[0], col, row)) w.fun=w.FUNCTION::ONE;
                else if(verify(w.boxes[1], col, row)) w.fun=w.FUNCTION::TWO;
                else if(verify(w.boxes[2], col, row)) w.fun=w.FUNCTION::THREE;
                else if(verify(w.boxes[3], col, row)) w.fun=w.FUNCTION::FOUR;
                else if(verify(w.boxes[4], col, row)) w.fun=w.FUNCTION::FIVE;
                else if(verify(w.boxes[5], col, row)) w.fun=w.FUNCTION::SIX;
                else if(verify(w.boxes[6], col, row)) w.fun=w.FUNCTION::SEVEN;
                else if(verify(w.boxes[7], col, row)) w.fun=w.FUNCTION::EIGHT;
                else if(verify(w.boxes[8], col, row)) w.fun=w.FUNCTION::NINE;
            }
        }

        cam=handleInput(cam);

        window.clear();

        w.draw(window); //FONDO PRIMERO
        f.selection(w, window, cam);
        //f.firstFunction(w, window); //CURVA ENCIMA
        drawAxisNumbers(window, w, cam, font);
        o.drawingBoxes(w, window);

        window.display();
    }
}


int main(){
    execute();
    return 0;
}
