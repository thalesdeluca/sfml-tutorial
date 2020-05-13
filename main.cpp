#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

  while (window.isOpen()) {
    sf::Event evt;
    while (window.pollEvent(evt)) {

      switch(evt.type) {
        case sf::Event::Closed: 
          window.close();
          break;
        case sf::Event::Resized:
          std::cout << evt.size.width << " " << evt.size.height << std::endl;  
      }

      if (evt.type == evt.Closed) {
        window.close();
      }
    }
  }

  return 0;
}