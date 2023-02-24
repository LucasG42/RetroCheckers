#include "../includes/Position.hpp"
#include "../includes/GameTypes.hpp"
void Position::showPosition() { std::cout << "(" << x << "," << y << ")\n"; }

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

bool Position::operator==(Position b) { return (x == b.x && y == b.y); }