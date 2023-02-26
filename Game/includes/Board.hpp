#ifndef BOARD_H
#define BOARD_H
#include "Piece.hpp"
#include "Position.hpp"
#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
class Board {
private:
  void Populate(sf::RenderWindow &window);

public:
  const int width = 8;
  const int heigth = 8;

  bool hasInitialized = false;
  std::vector<Tile> tiles;
  std::vector<Piece> pieces;
  Piece *selectedPiece = nullptr;
  Tile *previousTile = nullptr;
  Tile *captureTile = nullptr;
  void InitBoard(sf::RenderWindow &window);
  void CreateBoard(sf::RenderWindow &window);
  void Update(sf::RenderWindow &window);
};
#endif