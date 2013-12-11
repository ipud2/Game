#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"
#include "Tile.h"

Tile::Tile(Game* _game, int x, int y, bool collides, std::string model) : Entity(_game, model), X(x), Y(y), Collidable(collides)
{
    Type = TYPEID_TILE;
}

Tile::~Tile()
{
}

bool Tile::Intersects(sf::FloatRect& check, sf::FloatRect& intersection) const
{
    return sprite.getGlobalBounds().intersects(check, intersection);
}

