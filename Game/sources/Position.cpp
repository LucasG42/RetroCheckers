#include "../includes/Position.hpp"
#include "../includes/Board.hpp"
#include "../includes/GameTypes.hpp"

extern Board board;

void Position::showPosition() { std::cout << "(" << x << "," << y << ")\n"; }
bool Position::operator==(Position b) { return (x == b.x && y == b.y); }
Position Position::RelativePositionToAbsolutePosition(int textureWidth,
                                                      int textureHeigth) {
  return {((x * textureWidth) + StartPosition.x),
          ((y * textureHeigth) + StartPosition.y)};
}

Position Position::AbsolutePositionToRelativePosition(int textureWidth,
                                                      int textureHeigth) {
  return {(x - StartPosition.x) / textureWidth,
          (y - StartPosition.y) / textureHeigth};
}
int Position::RelativePositionToIndex() {

  int index = (y * 8 + x);

  return index;
}
