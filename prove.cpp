#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(400, 400)),
        "Linea SFML"
    );

    sf::VertexArray linea(sf::PrimitiveType::Lines, 2);

    linea[0].position = {10.f, 10.f};
    linea[0].color = sf::Color::Red;

    linea[1].position = {390.f, 390.f};
    linea[1].color = sf::Color::Blue;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(linea);
        window.display();
    }

    return 0;
}
