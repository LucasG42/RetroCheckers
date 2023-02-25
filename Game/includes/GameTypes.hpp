#include "Position.hpp"
#include <SFML/Graphics.hpp>
#ifndef GAMESTYPES_H
#define GAMESTYPES_H
enum Color { dark = 0, white = 1 };
enum Type { man = 0, king = 1 };
const Position StartPosition{168, 50};
const sf::Color RED = sf::Color::Red;
const sf::Color GREEN = sf::Color::Green;
#endif