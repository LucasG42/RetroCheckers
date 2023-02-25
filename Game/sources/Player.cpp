#include "../includes/Player.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Position.hpp"
#include <utility>
extern Board board;
std::vector<std::pair<Tile &, const sf::Color>>
Player::GetAvaliablesMoves(Tile &tile, std::vector<Tile> &tiles) {

  std::vector<std::pair<Tile &, const sf::Color>> avaliableMoves;
  tile.relativePosition.showPosition();
  avaliableMoves.reserve(4);
  int pivot = 1;
  if (tile.piece->color == Color::white) {
    pivot = -1;
  }
  int index = tile.relativePosition.RelativePositionToIndex();
  index = index + pivot * 8; // a frente

  int leftIndex = index - 1;

  if (leftIndex >= 0) {
    if (!tiles[leftIndex].hasPiece && tiles[leftIndex].relativePosition.y ==
                                          pivot + tile.relativePosition.y) {
      avaliableMoves.push_back(
          std::pair<Tile &, const sf::Color>(tiles[leftIndex], GREEN));
    }
  }

  int rightIndex = index + 1;
  if (rightIndex <= 63) {
    if (!tiles[rightIndex].hasPiece && tiles[rightIndex].relativePosition.y ==
                                           pivot + tile.relativePosition.y) {
      avaliableMoves.push_back(
          std::pair<Tile &, const sf::Color>(tiles[rightIndex], GREEN));
    }
  }

  if (tile.piece->type == Type::king) {
    index -= pivot * 8;
    index -= pivot * 8;

    int leftIndex = index - 1;
    if (leftIndex >= 0) {
      if (!tiles[leftIndex].hasPiece && tiles[leftIndex].relativePosition.y ==
                                            pivot + tile.relativePosition.y) {
        avaliableMoves.push_back(
            std::pair<Tile &, const sf::Color>(tiles[leftIndex], GREEN));
      }
    }

    int rightIndex = index + 1;
    if (rightIndex <= 63) {
      if (!tiles[rightIndex].hasPiece && tiles[rightIndex].relativePosition.y ==
                                             pivot + tile.relativePosition.y) {
        avaliableMoves.push_back(
            std::pair<Tile &, const sf::Color>(tiles[rightIndex], GREEN));
      }
    }
  }
  avaliableMoves.shrink_to_fit();
  return avaliableMoves;
}
void Player::MouseIsClicked(Position ClickPosition) {
  auto &tiles = board.tiles;
  for (auto &tile : tiles) {
    if (tile.hasPiece) {
      Position pos = ClickPosition.AbsolutePositionToRelativePosition(
          Tile::textureWidth, Tile::textureHeigth);
      if (pos == tile.relativePosition) {
        auto tilesToColorize = Player::GetAvaliablesMoves(tile, tiles);
        for (auto &tileToColirize : tilesToColorize) {
          tileToColirize.first.Colorize(tileToColirize.second);
        }
        break;
      }
    }
  }
}