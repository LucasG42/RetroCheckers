#include "../includes/Tile.hpp"
#include "../includes/GameTypes.hpp"
#include "../includes/Position.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
Tile::Tile(Color color, Position position) {
  this->color = color;
  this->absolutePosition = position;
  this->relativePosition = position.AbsolutePositionToRelativePosition(
      Tile::textureWidth, Tile::textureHeigth);

  std::string filepath =
      (color == white)
          ? "/home/lucas/Documentos/Checkers/Game/resources/white.png"
          : "/home/lucas/Documentos/Checkers/Game/resources/brown.png";

  if (!texture.loadFromFile(filepath)) {
    std::cout << "Erro ao carregar texture"
              << "\n";
  }

  sprite.setTexture(texture);
  sprite.setPosition(position.x, position.y);
}

sf::Sprite Tile::getSprite() { return sprite; }

void Tile::togglePiece() { hasPiece = !hasPiece; }
Position Tile::getPosition() { return absolutePosition; }

void Tile::Colorize(sf::Color color) { sprite.setColor(color); };