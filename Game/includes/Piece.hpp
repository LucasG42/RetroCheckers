#ifndef PIECE_H
#define PIECE_H
#include "GameTypes.hpp"
#include "Position.hpp"
#include "Tile.hpp"
#include <SFML/Graphics.hpp>

class Piece {
private:
  sf::Texture texture;
  sf::Sprite sprite;

public:
  bool alive = true;
  bool isSelected = false;
  Color color;
  static const int textureWidth = 50;
  static const int textureHeigth = 50;
  Position relativePosition;
  Position absolutePosition;
  Tile *myTile = nullptr;
  Type type;
  Piece(Color color, Type type, Position absolutePosition,
        Position relatovePosition);
  sf::Sprite getSprite();
  void turnKing();
  void Move(Tile &tile);
};
#endif