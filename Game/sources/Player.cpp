#include "../includes/Player.hpp"
#include "../includes/Position.hpp"
std::vector<Tile> Player::GetAvaliablesMoves(Tile &tile,
                                             std::vector<Tile> &tiles) {

  std::vector<Tile> avaliableMoves;
  std::cout << "Cliquei ";
  tile.relativePosition.showPosition();
  avaliableMoves.reserve(4);
  int pivot = 1;
  if (tile.piece->color == Color::white) {
    pivot = -1;
  }
  int index =
      (tile.relativePosition.y * 8 + tile.relativePosition.x) + pivot * 8;
  Tile k = tiles[index];
  std::cout << "A frente ";
  k.relativePosition.showPosition();

  int leftIndex = index - 1;
  if (leftIndex >= 0) {
    if (!tiles[leftIndex].hasPiece && tiles[leftIndex].relativePosition.y ==
                                          pivot + tile.relativePosition.y) {

      tiles[leftIndex].Colorize(sf::Color::Green);
      std::cout << "Colori o esquerda ";
      tiles[leftIndex].relativePosition.showPosition();
    }
  }

  int rightIndex = index + 1;
  if (rightIndex <= 63) {
    if (!tiles[rightIndex].hasPiece && tiles[rightIndex].relativePosition.y ==
                                           pivot + tile.relativePosition.y) {

      tiles[rightIndex].Colorize(sf::Color::Green);
      std::cout << "Colori o direita";
      tiles[rightIndex].relativePosition.showPosition();
    }
  }

  avaliableMoves.shrink_to_fit();

  return avaliableMoves;
}
void Player::MouseIsClicked(Position ClickPosition, Board &board) {
  auto &tiles = board.tiles;
  for (auto &tile : tiles) {
    if (tile.hasPiece) {
      Position pos = ClickPosition.AbsolutePositionToRelativePosition(
          Tile::textureWidth, Tile::textureHeigth);
      if (pos == tile.relativePosition) {
        Player::GetAvaliablesMoves(tile, tiles);
        break;
      }
    }
  }
}