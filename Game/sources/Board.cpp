#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Piece.hpp"
#include "../includes/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <math.h>
#include <thread>

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
    if (i % width == 0) {
      pos.y += Tile::textureHeigth;
      pos.x = StartPosition.x;
      color = invertColor(color);
    }
    color = invertColor(color);
  }
}
void Board::Populate(sf::RenderWindow &window) {
  Piece *piece;
  Position pos;
  int ratio = 5;
  int index = 0;
  std::vector<Position> whiteInitialPosition = {
      {0, 5}, {2, 5}, {4, 5}, {6, 5}, {1, 6}, {3, 6},
      {5, 6}, {7, 6}, {0, 7}, {2, 7}, {4, 7}, {6, 7},
  };
  std::vector<Position> blackInitialPosition = {
      {1, 0}, {3, 0}, {5, 0}, {7, 0}, {0, 1}, {2, 1},
      {4, 1}, {6, 1}, {1, 2}, {3, 2}, {5, 2}, {7, 2},
  };

  for (Position initPos : whiteInitialPosition) {
    int index = initPos.RelativePositionToIndex();
    pos = {
        tiles[index].getPosition().x + ratio,
        tiles[index].getPosition().y + ratio,
    };
    tiles[index].togglePiece();
    piece = new Piece(Color::white, Type::man, pos, initPos);
    pieces.push_back(*piece);
  }

  for (Position initPos : blackInitialPosition) {
    int index = initPos.RelativePositionToIndex();
    pos = {
        tiles[index].getPosition().x + ratio,
        tiles[index].getPosition().y + ratio,
    };
    tiles[index].togglePiece();
    piece = new Piece(Color::dark, Type::man, pos, initPos);
    pieces.push_back(*piece);
  }
}
void Board::Update(sf::RenderWindow &window) {

  for (auto &tile : tiles) {
    window.draw(tile.getSprite());
    window.draw(tile.getSelectedSprite());
  }
  for (auto piece : pieces) {
    if (piece.alive == true) {
      window.draw(piece.getSprite());
    }
  }
};
