#ifndef PLAYER_H
#define PLAYER_H
#include "Board.hpp"
#include "Position.hpp"
#include <utility>
#include <vector>
class Player {
private:
  std::vector<std::tuple<Tile &, const sf::Color, Tile *>>
  GetAvaliablesMoves(Piece &piece, std::vector<Tile> &tiles);
  Color color = Color::white;

public:
  void invertColor();
  void MouseIsClicked(Position ClickPosition);
};
#endif