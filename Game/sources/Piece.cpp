#include "../includes/Piece.hpp"
#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Position.hpp"
#include "../includes/Tile.hpp"
#include <iostream>
#include <string>

Piece::Piece(Color color, Type type, Position position) {
  std::string filepath;
  if (color) {
    // White
    if (type) {
      // King
      filepath = "/home/lucas/Documentos/Checkers/Game/resources/KingWhite.png";
    } else {
      // Man
      filepath = "/home/lucas/Documentos/Checkers/Game/resources/ManWhite.png";
    }
  } else {
    // Black
    if (type) {
      // King
      filepath = "/home/lucas/Documentos/Checkers/Game/resources/KingBlack.png";
    } else {
      // Man
      filepath = "/home/lucas/Documentos/Checkers/Game/resources/ManBlack.png";
    }
  }

  if (!texture.loadFromFile(filepath)) {
    std::cout << "Erro ao carregar textura"
              << "\n";
  }
  isSelected = false;
  this->type = type;
  this->color = color;
  this->relativePosition = {((position.x - StartPosition.x) / textureWidth),
                            ((position.y - StartPosition.y) / textureHeigth)};
  this->position = position;
  sprite.setTexture(texture);
  sprite.setPosition(position.x, position.y);
}

sf::Sprite Piece::getSprite() { return sprite; }

void Piece::turnKing() {
  sf::Image kingTexture;
  type = Type::king;
  if (color == Color::white) {
    kingTexture.loadFromFile(
        "/home/lucas/Documentos/Checkers/Game/resources/KingWhite.png");
  } else {
    kingTexture.loadFromFile(
        "/home/lucas/Documentos/Checkers/Game/resources/KingBlack.png");
  }
  texture.update(kingTexture);
  sprite.setTexture(texture);
}

/*void Piece::getAvaliablesMoves(int index, Board &board) {
  // change to width of board
  auto &tiles = board.tiles;
  if (tiles[index + 8].hasPiece == false) {
    tiles[index + 8].getSprite().setColor(sf::Color(200, 200, 50));
  }
}
*/
