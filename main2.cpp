#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

constexpr int TILE=5;

/* 
  MATRIZ DE ROTACION 2D
  x' =[cos(alpha) -sin(alpha)] [x]
  y' =[sin(alpha) cos(alpha) ] [y]
*/

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
                }
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

    //I DON'T HAVE FUCKING TIMEEEE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void saveBoxes(World& w){
        BOXES Box1;
        Box1.position={TILE*2, TILE*2}; //columna, fila
        Box1.weight=TILE*20; //anchura
        Box1.height=TILE*10; //altura
        w.boxes.push_back(Box1);

        BOXES Box2;
        Box2.position={TILE*2, TILE*14};
        Box2.weight=TILE*20;
        Box2.height=TILE*10;
        w.boxes.push_back(Box2);

        BOXES Box3;
        Box3.position={TILE*2, TILE*26};
        Box3.weight=TILE*20;
        Box3.height=TILE*10;
        w.boxes.push_back(Box3);

        BOXES Box4;
        Box4.position={TILE*2, TILE*38};
        Box4.weight=TILE*20;
        Box4.height=TILE*10;
        w.boxes.push_back(Box4);

        BOXES Box5;
        Box5.position={TILE*2, TILE*50};
        Box5.weight=TILE*20;
        Box5.height=TILE*10;
        w.boxes.push_back(Box5);

        BOXES Box6;
        Box6.position={TILE*2, TILE*62};
        Box6.weight=TILE*20;
        Box6.height=TILE*10;
        w.boxes.push_back(Box6);

        BOXES Box7;
        Box7.position={TILE*2, TILE*74};
        Box7.weight=TILE*20;
        Box7.height=TILE*10;
        w.boxes.push_back(Box7);

        BOXES Box8;
        Box8.position={TILE*2, TILE*86};
        Box8.weight=TILE*20;
        Box8.height=TILE*10;
        w.boxes.push_back(Box8);

        BOXES Box9;
        Box9.position={TILE*2, TILE*98};
        Box9.weight=TILE*20;
        Box9.height=TILE*10;
        w.boxes.push_back(Box9);
    }

    void drawingBoxes(World& w, sf::RenderWindow& window){
        sf::RectangleShape box1(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box1.setFillColor(sf::Color::Green);
        box1.setPosition(sf::Vector2f(TILE*2, TILE*2));
        window.draw(box1); 
        
        texts[0].setString("Rotate to\n the Left");
        texts[0].setPosition(sf::Vector2f(TILE*3, TILE*3));
        window.draw(texts[0]); 

        sf::RectangleShape box2(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box2.setFillColor(sf::Color::Blue);
        box2.setPosition(sf::Vector2f(TILE*2, TILE*14));
        window.draw(box2); 

        texts[1].setString("Rotate to\n the Right");
        texts[1].setPosition(sf::Vector2f(TILE*3, TILE*15));
        window.draw(texts[1]); 

        sf::RectangleShape box3(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box3.setFillColor(sf::Color::Yellow);
        box3.setPosition(sf::Vector2f(TILE*2, TILE*26));
        window.draw(box3); 

        texts[2].setString("f(x)=y=x^2");
        texts[2].setPosition(sf::Vector2f(TILE*3, TILE*27));
        window.draw(texts[2]);

        sf::RectangleShape box4(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box4.setFillColor(sf::Color::Red);
        box4.setPosition(sf::Vector2f(TILE*2, TILE*38));
        window.draw(box4); 

        texts[3].setString("f(x)=y=sen(x)");
        texts[3].setPosition(sf::Vector2f(TILE*3, TILE*39));
        window.draw(texts[3]); 

        sf::RectangleShape box5(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box5.setFillColor(sf::Color::Cyan);
        box5.setPosition(sf::Vector2f(TILE*2, TILE*50));
        window.draw(box5);

        texts[4].setString("f(x)=y=cos(x)");
        texts[4].setPosition(sf::Vector2f(TILE*3, TILE*51));
        window.draw(texts[4]);

        sf::RectangleShape box6(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box6.setFillColor(sf::Color::White);
        box6.setPosition(sf::Vector2f(TILE*2, TILE*62));
        window.draw(box6); 

        texts[5].setString("f(x)=y=tan(x)");
        texts[5].setPosition(sf::Vector2f(TILE*3, TILE*63));
        window.draw(texts[5]);

        sf::RectangleShape box7(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box7.setFillColor(sf::Color::Magenta);
        box7.setPosition(sf::Vector2f(TILE*2, TILE*74));
        window.draw(box7); 

        texts[6].setString("f(x)=y=cosc(x)");
        texts[6].setPosition(sf::Vector2f(TILE*3, TILE*75));
        window.draw(texts[6]);

        sf::RectangleShape box8(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box8.setFillColor(sf::Color::Green);
        box8.setPosition(sf::Vector2f(TILE*2, TILE*86));
        window.draw(box8); 

        texts[7].setString("f(x)=y=sec(x)");
        texts[7].setPosition(sf::Vector2f(TILE*3, TILE*87));
        window.draw(texts[7]);

        sf::RectangleShape box9(sf::Vector2f(TILE*20, TILE*10)); //anchura, altura
        box9.setFillColor(sf::Color::Blue);
        box9.setPosition(sf::Vector2f(TILE*2, TILE*98));
        window.draw(box9);

        texts[8].setString("f(x)=y=cot(x)");
        texts[8].setPosition(sf::Vector2f(TILE*3, TILE*99));
        window.draw(texts[8]);
    }
};

struct Camera{
    float offsetx=0;
    float offsety=0;
    float zoom=1.0f;
};

struct Functions{
    float angle=0.0f;

    enum Selected{Nothing, Square, Sin, Cos, Tan, Cosc, Sec, Cot};
    Selected selected=Nothing;

    bool rotLeft=false;
    bool rotRight=false;
    
    inline void rotate(float& x, float& y, float& angle){
        float xr=x*std::cos(angle) - y*std::sin(angle);
        float yr=x*std::sin(angle) + y*std::cos(angle);
        x=xr;
        y=yr;
    }

    void selection(World& w, sf::RenderWindow& window, Camera& cam){
        if(rotLeft) angle+=0.01f;
        if(rotRight) angle-=0.01f;

        if(w.fun==w.FUNCTION::ONE){
            rotLeft=true;
            rotRight=false; //AGREGADO
            if(selected==Square) funcSquare(w, window, cam);
            if(selected==Sin) funcSen(w, window, cam);
            if(selected==Cos) funcCos(w, window, cam);
            if(selected==Tan) funcTan(w, window, cam);
            if(selected==Cosc) funcCosc(w, window, cam);
            if(selected==Sec) funcSec(w, window, cam);
            if(selected==Cot) funcCot(w, window, cam);
        }
        if(w.fun==w.FUNCTION::TWO){
            rotLeft=false; //agregado
            rotRight=true;
            if(selected==Square) funcSquare(w, window, cam);
            if(selected==Sin) funcSen(w, window, cam);
            if(selected==Cos) funcCos(w, window, cam);
            if(selected==Tan) funcTan(w, window, cam);
            if(selected==Cosc) funcCosc(w, window, cam);
            if(selected==Sec) funcSec(w, window, cam);
            if(selected==Cot) funcCot(w, window, cam);
        }
        if(w.fun==w.FUNCTION::THREE){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Square;
            funcSquare(w, window, cam);
        }
        if(w.fun==w.FUNCTION::FOUR){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Sin;
            funcSen(w, window, cam);
        }
        if(w.fun==w.FUNCTION::FIVE){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Cos;
            funcCos(w, window, cam);
        }
        if(w.fun==w.FUNCTION::SIX){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Tan;
            funcTan(w, window, cam);
        }
        if(w.fun==w.FUNCTION::SEVEN){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Cosc;
            funcCosc(w, window, cam);
        }
        if(w.fun==w.FUNCTION::EIGHT){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Sec;
            funcSec(w, window, cam);
        }
        if(w.fun==w.FUNCTION::NINE){
            angle=0.0f;
            rotLeft=false;
            rotRight=false;
            selected=Cot;
            funcCot(w, window, cam);
        }
    } 

    void funcSquare(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        int scale=10;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float y=(x*x)/float(scale);

            //ROTACION
            if(rotLeft && selected==Square) rotate(xf, y, angle);
            if(rotRight && selected==Square) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }
        window.draw(curve);
    }

    void funcSen(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=std::sin(x*freq)*amplitude; ///float(scale);
                                                
            //ROTACION
            if(rotLeft && selected==Sin) rotate(xf, y, angle);
            if(rotRight && selected==Sin) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }
        window.draw(curve);
    }

    void funcCos(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;

        //float angle=0.5f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=std::cos(x*freq)*amplitude;

            //ROTACION
            if(rotLeft && selected==Cos) rotate(xf, y, angle);
            if(rotRight && selected==Cos) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }

    void funcTan(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;
        //float angle=0.5f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=std::tan(x*freq)*amplitude;

            //ROTACION
            if(rotLeft && selected==Tan) rotate(xf, y, angle);
            if(rotRight && selected==Tan) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
    
    void funcCosc(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;
        //float angle=0.5f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=(1/std::sin(x*freq))*amplitude;

            //ROTACION
            if(rotLeft && selected==Cosc) rotate(xf, y, angle);
            if(rotRight && selected==Cosc) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
    
    void funcSec(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;
        //float angle=0.5f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=(1/std::cos(x*freq))*amplitude;

            //ROTACION
            if(rotLeft && selected==Sec) rotate(xf, y, angle);
            if(rotRight && selected==Sec) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
    
    void funcCot(World& w, sf::RenderWindow& window, Camera& cam){
        sf::VertexArray curve(sf::PrimitiveType::LineStrip);
        float amplitude=10.0f;
        //float angle=0.5f;

        for(int x=-w.middle; x<w.middle; x++){
            float xf=float(x);
            float freq=0.15f;
            float y=(1/std::tan(x*freq))*amplitude;

            //ROTACION
            if(rotLeft && selected==Cot) rotate(xf, y, angle);
            if(rotRight && selected==Cot) rotate(xf, y, angle);

            float px=((xf+w.middle)*TILE+cam.offsetx)*cam.zoom;
            float py=((w.middle-y)*TILE+cam.offsety)*cam.zoom;

            sf::Vertex v;
            v.position=sf::Vector2f(px,py);
            v.color=sf::Color::Green;

            curve.append(v);
        }

        window.draw(curve);
    }
};

bool verify(BOXES& box, int& row, int& col){
    return (
        col >= box.position.first &&
        col <= box.position.first + box.weight &&
        row >= box.position.second &&
        row <= box.position.second + box.height
    );
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

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(TILE*w.col), //COLUMNAS 
                static_cast<unsigned>(TILE*w.row)  //FILAS
        }), "GRAPHICS 2D"
    };

    window.setFramerateLimit(60);

    o.saveBoxes(w);

    //------------------ZONA TEXT--------------------
    sf::Font font;
    if(!font.openFromFile("arial.ttf")) std::cerr<<"No se pudo cargar el archivo\n";

    o.init(font); //este crea los textos que se usarà
    //-----------------------------------------------

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close();
            if(const auto* mouseButtonPressed=event->getIf<sf::Event::MouseButtonPressed>()){
                int col=mouseButtonPressed->position.x; //LE EH BORRADO TILE
                int row=mouseButtonPressed->position.y;

                //std::cout<<"COL MOUSE: "<<col<<std::endl;
                //std::cout<<"ROW MOUSE: "<<row<<std::endl;
                
                //TIENE QUE SER CAJA POR CAJA
                if(verify(w.boxes[0], row, col)) w.fun=w.FUNCTION::ONE;
                else if(verify(w.boxes[1], row, col)) w.fun=w.FUNCTION::TWO;
                else if(verify(w.boxes[2], row, col)) w.fun=w.FUNCTION::THREE;
                else if(verify(w.boxes[3], row, col)) w.fun=w.FUNCTION::FOUR;
                else if(verify(w.boxes[4], row, col)) w.fun=w.FUNCTION::FIVE;
                else if(verify(w.boxes[5], row, col)) w.fun=w.FUNCTION::SIX;
                else if(verify(w.boxes[6], row, col)) w.fun=w.FUNCTION::SEVEN;
                else if(verify(w.boxes[7], row, col)) w.fun=w.FUNCTION::EIGHT;
                else if(verify(w.boxes[8], row, col)) w.fun=w.FUNCTION::NINE;
            }
        }

        cam=handleInput(cam);

        window.clear();

        w.draw(window); //FONDO PRIMERO
        f.selection(w, window, cam);
        drawAxisNumbers(window, w, cam, font);
        o.drawingBoxes(w, window);

        window.display();
    }
}


int main(){
    execute();
    return 0;
}
