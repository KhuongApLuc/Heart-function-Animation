#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#define WIDTH 800
#define HEIGHT 600

void draw_graph(sf::RenderWindow &window, float a) {
    window.clear(sf::Color::White);
    
    std::vector<sf::Vertex> points;
    for (int i = 0; i < WIDTH; ++i) {
        float x = (i - WIDTH / 2) * (2.0f * std::sqrt(33) / WIDTH);
        float y = std::pow(std::abs(x), 2.0f/3.0f) + 0.8f * std::sqrt(33 - x * x) * std::sin(0.01f * a * M_PI * x);
        int screen_y = HEIGHT / 2 - static_cast<int>(y * 20);
        points.push_back(sf::Vertex(sf::Vector2f(i, screen_y), sf::Color::Black));
    }
    
    window.draw(&points[0], points.size(), sf::Points);
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Graph Animation");
    
    float a = 1;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        draw_graph(window, a);
        a += 1;
        sf::sleep(sf::milliseconds(20));
    }
    
    return 0;
}
