#ifndef TILE_H
#define TILE_H
#include "GameTypes.hpp"
#include "Piece.hpp"
#include <SFML/Graphics.hpp>
class Tile {

  sf::Texture texture;
  sf::Sprite sprite;

public:
  Position absolutePosition;
  Position relativePosition;
  Color color;
  bool hasPiece = false;
  static const int textureWidth = 59;
  static const int textureHeigth = 59;
  void togglePiece();
  Piece *piece = nullptr;
  Tile(Color color, Position position);
  sf::Sprite getSprite();
  Position getPosition();
  void Colorize(sf::Color color);
};
#endif