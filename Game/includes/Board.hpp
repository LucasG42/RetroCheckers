#ifndef BOARD_H
#define BOARD_H
#include "Piece.hpp"
#include "Position.hpp"
#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
class Board {
  const int width = 8;
  const int heigth = 8;

private:
  void Populate(sf::RenderWindow &window);

public:
  bool hasInitialized = false;
  std::vector<Tile> tiles;
  std::vector<Piece> piece;
  void InitBoard(sf::RenderWindow &window);
  void CreateBoard(sf::RenderWindow &window);
  int getBoardSize();
  void Update(sf::RenderWindow &window);
};
#endif