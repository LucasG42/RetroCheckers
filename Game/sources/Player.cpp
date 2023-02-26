#include "../includes/Player.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Position.hpp"
#include <utility>
extern Board board;
static void GetAvaliablesMovesByDirection(
    int index, Piece &piece, std::vector<Tile> &tiles, Direction direction,
    int pivot,
    std::vector<std::tuple<Tile &, const sf::Color, Tile *>> &avaliableMoves) {

  Tile *captureTile = nullptr;
  index += direction;
  if (tiles[index].relativePosition.y == pivot + piece.relativePosition.y) {
    if (tiles[index].hasPiece) {
      for (auto &target : board.pieces) {
        if (target.relativePosition == tiles[index].relativePosition) {
          if (target.color != piece.color) {
            if (tiles[index + direction + (piece.color * board.width)]
                    .hasPiece == false) {
              captureTile = &(tiles[index]);
              index += pivot * board.width;
              index += direction;
              if (tiles[index].color == dark) {
                avaliableMoves.push_back(
                    std::tuple<Tile &, const sf::Color, Tile *>(
                        tiles[index], RED, captureTile));
              }
            }
            break;
          }
        }
      }
    } else {
      avaliableMoves.push_back(std::tuple<Tile &, const sf::Color, Tile *>(
          tiles[index], GREEN, captureTile));
    }
  }
}

std::vector<std::tuple<Tile &, const sf::Color, Tile *>>
Player::GetAvaliablesMoves(Piece &piece, std::vector<Tile> &tiles) {
  std::vector<std::tuple<Tile &, const sf::Color, Tile *>> avaliableMoves;
  avaliableMoves.reserve(4);
  int index = piece.relativePosition.RelativePositionToIndex();
  index = index + piece.color * board.width;
  int pivot = piece.color;
  GetAvaliablesMovesByDirection(index, piece, tiles, Direction::right, pivot,
                                avaliableMoves);
  GetAvaliablesMovesByDirection(index, piece, tiles, Direction::left, pivot,
                                avaliableMoves);
  if (piece.type == Type::king) {
    index -= piece.color * board.width;
    index -= piece.color * board.width;
    pivot = -pivot;
    GetAvaliablesMovesByDirection(index, piece, tiles, Direction::right, pivot,
                                  avaliableMoves);
    GetAvaliablesMovesByDirection(index, piece, tiles, Direction::left, pivot,
                                  avaliableMoves);
  }
  return avaliableMoves;
}

void Player::invertColor() {
  if (color == white) {
    color = dark;
  } else {
    color = white;
  }
}
void Player::MouseIsClicked(Position ClickPosition) {
  static std::vector<std::tuple<Tile &, const sf::Color, Tile *>>
      tilesToColorize;
  auto &pieces = board.pieces;
  auto &tiles = board.tiles;

  for (auto &tile : tiles) {
    tile.UnSelect();
  }

  for (auto &tile : tiles) {
    Position pos = ClickPosition.AbsolutePositionToRelativePosition(
        Tile::textureWidth, Tile::textureHeigth);
    if (pos == tile.relativePosition) {
      if (tile.hasPiece) {
        for (auto &piece : pieces) {
          if (piece.relativePosition == tile.relativePosition) {
            if (piece.color == color) {
              for (auto &tile : tiles) {
                tile.isColorized = false;
              }
              board.selectedPiece = &piece;
              tilesToColorize = Player::GetAvaliablesMoves(piece, tiles);
              board.previousTile = &tile;
              for (auto &tileToColirize : tilesToColorize) {
                std::get<0>(tileToColirize).isColorized = true;
                std::get<0>(tileToColirize)
                    .Colorize(std::get<1>(tileToColirize));
              }
              break;
            }
          }
        }
      } else if (tile.isColorized) {
        if (tile.relativePosition.y == 7 || tile.relativePosition.y == 0) {
          board.selectedPiece->turnKing();
        }
        for (auto &tileToColorize : tilesToColorize) {
          auto &ColorizedTile = std::get<0>(tileToColorize);
          auto &color = std::get<1>(tileToColorize);
          auto &CapturedTile = std::get<2>(tileToColorize);
          ColorizedTile.isColorized = false;
          if (ColorizedTile.relativePosition == tile.relativePosition) {
            if (color == RED && CapturedTile != nullptr) {
              for (auto &piece : pieces) {
                if (piece.relativePosition == CapturedTile->relativePosition) {
                  piece.relativePosition.showPosition();
                  piece.alive = false;
                  CapturedTile->togglePiece();
                  break;
                }
              }
            }
          }
        }

        tile.togglePiece();
        board.previousTile->togglePiece();
        board.selectedPiece->Move(tile);
        invertColor();
      }
      break;
    }
  }
}