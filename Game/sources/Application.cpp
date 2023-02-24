#include "../includes/Application.hpp"
#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Piece.hpp"
#include "../includes/Player.hpp"
#include "../includes/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
int Application::InitApp() {
  sf::RenderWindow window(sf::VideoMode(windowsWidth, windowsHeigth), title);
  sf::Color backgroundColor(12, 112, 39);
  Board board;
  Player player;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed) {

        player.MouseIsClicked({sf::Mouse::getPosition(window).x,
                               sf::Mouse::getPosition(window).y},
                              board);
      }
    }
    window.clear(backgroundColor);
    if (!board.hasInitialized) {
      board.InitBoard(window);
      board.hasInitialized = true;
    }
    board.Update(window);
    window.display();
  }

  return 0;
}