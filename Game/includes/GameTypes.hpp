#include "Position.hpp"
#include <SFML/Graphics.hpp>
#ifndef GAMESTYPES_H
#define GAMESTYPES_H
enum Color { dark = 1, white = -1 };
enum Type { man = 0, king = 1 };
enum Direction { left = -1, right = 1 };
enum Movement { move, capture };
const Position StartPosition{0, 0};
const sf::Color RED = sf::Color::Red;
const sf::Color GREEN = sf::Color::Green;
#endif