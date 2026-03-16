#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

constexpr int TILE=14;

struct Funcions{

};

struct World{
    std::vector<std::vector<int>> world={
        50, std::vector<int>(50, 0)
    };

    int row=world.size();
    int col=world[0].size();

    void draw(sf::RenderWindow& window){
        sf::RectangleShape block(sf::Vector2f(TILE, TILE));
        block.setFillColor(sf::Color::Blue);

        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                if(world[i][j]==0){
                    block.setPosition(sf::Vector2f(j*TILE, i*TILE));
                    window.draw(block);
                }
            }
        }
    }

    void drawInput(sf::RenderWindow& window, sf::Text& text){
        window.draw(text);
    }
};

void initText(sf::Text& text, sf::Font& font){ 
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(TILE*50, TILE*25));
}

void execute(){

    World w;

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(TILE*w.col), //COLUMNAS 
                static_cast<unsigned>(TILE*w.row)  //FILAS
        }), "GRAPHICS 2D"
    };

    window.setFramerateLimit(60);

    sf::Font font;
    if(!font.openFromFile("arial.ttf")) std::cerr<<"Error loading font file"<<std::endl;

    sf::Text text(font, "", 30);
    initText(text, font); 

    std::string userInput;
    sf::String sfUserInput;

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close();

            //CAPTURAR TEXTO
            if(const auto* textEntered=event->getIf<sf::Event::TextEntered>()){
                if(textEntered->unicode<128){
                    if(textEntered->unicode=='\b'){
                        if(!userInput.empty()) userInput.erase(userInput.size()-1);
                    }else if(textEntered->unicode=='\r' || textEntered->unicode=='\n'){
                        //ACCIONAR SI PRESIONA ENTER
                    }else userInput+=static_cast<char>(textEntered->unicode);

                    sfUserInput=userInput;
                    text.setString(sfUserInput);
                }
            }
        }

        window.clear();
        w.draw(window);
        w.drawInput(window, text);
        window.display();
    }
}

int main(){
    execute();
    return 0;
}

//g++ -o m main.cpp -lsfml-graphics -lsfml-window -lsfml-system
