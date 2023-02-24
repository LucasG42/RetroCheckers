#include <iostream>
#ifndef POSITION_H
#define POSITION_H
class Position {
public:
  int x;
  int y;
  void showPosition();
  Position AbsolutePositionToRelativePosition(int textureWidth,
                                              int textureHeigth);
  Position RelativePositionToAbsolutePosition(int textureWidth,
                                              int textureHeigth);
  bool operator==(Position b);
};
#endif