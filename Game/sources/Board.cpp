#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Piece.hpp"
#include "../includes/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

Color invertColor(Color color) {
  if (color == Color::white) {
    return Color::dark;
  } else {
    return Color::white;
  }
}
void Board::InitBoard(sf::RenderWindow &window) {
  Board::CreateBoard(window);
  Board::Populate(window);
}

void Board::CreateBoard(sf::RenderWindow &window) {
  Position pos = StartPosition;
  Color color = Color::white;
  int boardSize = width * heigth;
  tiles.reserve(boardSize);
  Tile *tile;
  for (int i = 1; i <= boardSize; i++) {
    tile = new Tile(color, pos);
    tiles.push_back(*tile);
    pos.x += Tile::textureWidth;
    if (i % 8 == 0) {
      pos.y += Tile::textureHeigth;
      pos.x = StartPosition.x;
      color = invertColor(color);
    }
    color = invertColor(color);
  }
}
void Board::Populate(sf::RenderWindow &window) {

  int i = 0;
  Position pos;
  int ratio = 5;
  int index = 0;
  for (int i = 0; i < 24; i += 2) {
    index = i;
    if (i > 7 && i < 15) {
      index = index + 1;
    }
    pos = {tiles[index].getPosition().x + ratio,
           tiles[index].getPosition().y + ratio};
    tiles[index].togglePiece();
    Piece *piece = new Piece(Color::dark, Type::man, pos);
    tiles[index].piece = piece;
    window.draw(piece->getSprite());
  }

  for (int i = 40; i < 64; i += 2) {
    index = i;
    if (i > 47 && i < 55) {
      index = index + 1;
    }
    pos = {tiles[index].getPosition().x + ratio,
           tiles[index].getPosition().y + ratio};
    tiles[index].togglePiece();
    Piece *piece = new Piece(Color::white, Type::man, pos);
    tiles[index].piece = piece;
    window.draw(piece->getSprite());
  }
  // make it responsible to differetns types of boards
}
void Board::Update(sf::RenderWindow &window) {
  for (auto tile : tiles) {
    window.draw(tile.getSprite());
    if (tile.hasPiece) {
      window.draw(tile.piece->getSprite());
    }
  }
};
