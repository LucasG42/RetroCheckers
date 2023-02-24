#ifndef PLAYER_H
#define PLAYER_H
#include "Board.hpp"
#include "Position.hpp"
#include <vector>
class Player {
private:
  std::vector<Tile> GetAvaliablesMoves(Tile &tile, std::vector<Tile> &tiles);

public:
  void MouseIsClicked(Position ClickPosition, Board &board);
};
#endif