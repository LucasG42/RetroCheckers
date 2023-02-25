#ifndef PLAYER_H
#define PLAYER_H
#include "Board.hpp"
#include "Position.hpp"
#include <utility>
#include <vector>
class Player {
private:
  std::vector<std::pair<Tile &, const sf::Color>>
  GetAvaliablesMoves(Tile &tile, std::vector<Tile> &tiles);

public:
  void MouseIsClicked(Position ClickPosition);
};
#endif