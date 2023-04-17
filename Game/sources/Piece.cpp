#include "../includes/Piece.hpp"
#include "../includes/Application.hpp"
#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Position.hpp"
#include "../includes/Tile.hpp"
#include <iostream>
#include <string>

Piece::Piece(Color color, Type type, Position absolutePosition,
             Position relativePosition) {
  std::string filepath;
  if (color == white) {
    // White
    if (type) {
      // King
      filepath = resourcesPath + "KingWhite.png";
    } else {
      // Man
      filepath = resourcesPath + "ManWhite.png";
    }
  } else {
    // Black
    if (type) {
      // King
      filepath = resourcesPath + "KingBlack.png";
    } else {
      // Man
      filepath = resourcesPath + "ManBlack.png";
    }
  }

  if (!texture.loadFromFile(filepath)) {
    std::cout << "Erro ao carregar textura"
              << "\n";
  }
  isSelected = false;
  this->type = type;
  this->color = color;
  this->relativePosition = relativePosition;
  this->absolutePosition = absolutePosition;
  sprite.setTexture(texture);
  sprite.setPosition(absolutePosition.x, absolutePosition.y);
}

sf::Sprite Piece::getSprite() { return sprite; }

void Piece::turnKing() {
  sf::Image kingTexture;
  type = Type::king;
  if (color == Color::white) {
    kingTexture.loadFromFile(resourcesPath + "KingWhite.png");
  } else {
    kingTexture.loadFromFile(resourcesPath + "KingBlack.png");
  }
  texture.update(kingTexture);
  sprite.setTexture(texture);
}

void Piece::Move(Tile &tile) {
  myTile = &tile;
  relativePosition = tile.relativePosition;
  absolutePosition = tile.relativePosition.RelativePositionToAbsolutePosition(
      tile.textureWidth, tile.textureHeigth);
  absolutePosition.x += 5;
  absolutePosition.y += 5;
  sprite.setPosition(absolutePosition.x, absolutePosition.y);
}
