#ifndef TILE_H
#define TILE_H
#include "GameTypes.hpp"
#include <SFML/Graphics.hpp>
class Tile {

  sf::Texture texture;
  sf::Sprite sprite;
  sf::Sprite selectedSprite;

public:
  Position absolutePosition;
  Position relativePosition;
  Color color;
  bool hasPiece = false;
  bool isColorized = false;
  static const int textureWidth = 60;
  static const int textureHeigth = 60;
  void togglePiece();
  Tile(Color color, Position position);
  sf::Sprite getSprite();
  sf::Sprite getSelectedSprite();
  Position getPosition();
  void Colorize(sf::Color color);
  void UnSelect();
};
#endif