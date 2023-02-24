#ifndef PIECE_H
#define PIECE_H
#include "GameTypes.hpp"
#include "Position.hpp"
#include <SFML/Graphics.hpp>

class Piece {
private:
  sf::Texture texture;
  sf::Sprite sprite;

public:
  Color color;
  static const int textureWidth = 50;
  static const int textureHeigth = 50;
  Position relativePosition;
  Position position;
  Type type;
  Piece(Color color, Type type, Position position);
  sf::Sprite getSprite();
  void turnKing();
  void Move(Position newPosition);
};
#endif