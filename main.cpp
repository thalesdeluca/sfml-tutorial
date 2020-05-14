#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
  sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
  sf::Texture playerTexture;
  playerTexture.loadFromFile("Textures/spritesheet.png");
  player.setTexture(&playerTexture);

  sf::Vector2u textureSize = playerTexture.getSize();
  textureSize.x /= 5;
  textureSize.y /= 2;

  player.setTextureRect(sf::IntRect(textureSize.x, textureSize.y, textureSize.x, textureSize.y));

  player.setOrigin(50.0f, 50.0f);

  while (window.isOpen()) {
    sf::Event evt;
    while (window.pollEvent(evt)) {
       window.clear();

      switch(evt.type) {
        case sf::Event::Closed: 
          window.close();
          break;
        case sf::Event::Resized:
          std::cout << evt.size.width << " " << evt.size.height << std::endl;  
        case sf::Event::TextEntered:
          if(evt.text.unicode < 128) {
            printf("%c", evt.text.unicode);
          }

          break;
      }

      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        player.setPosition(static_cast<float>(mousePos.x),static_cast<float>(mousePos.y));
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
          player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y* 0, textureSize.x, textureSize.y));
        player.move(-0.5f, 0);
      }
        
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        player.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y*0, textureSize.x, textureSize.y));
        player.move(0.0f, 0.5f);
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        player.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y*00, textureSize.x, textureSize.y));
        player.move(0.0f, -0.5f);
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        player.setTextureRect(sf::IntRect(textureSize.x, textureSize.y*0, textureSize.x, textureSize.y));
        player.move(0.5f, 0);
      }


      window.draw(player);
      window.display();

     
      if (evt.type == evt.Closed) {
        window.close();
      }
    }
  }

  return 0;
}