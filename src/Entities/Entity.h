#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include "SharedDefines.h"

class Game;
class Map;
class Unit;

class Entity
{
public:
    Entity(Game* _game, std::string model);
    virtual ~Entity();

    virtual void Update(sf::Time const diff);
    virtual void Draw();

    virtual void LoadTexture();
    virtual void LoadMoveTexture(int type) = 0;

    virtual TypeId GetTypeId() const { return Type; }

    virtual float GetPositionX() const { return Position.x; }
    virtual float GetPositionY() const { return Position.y; }

    virtual void SetPosition(sf::Vector2f pos);

    virtual bool IsInAir() const { return inAir; };

    virtual void AddToMap(Map* _map) { map = _map; }

    virtual void StopMoving(sf::Vector2f alongAxis) = 0;
    
    Unit* ToUnit();

    sf::Vector2f NewPosition;
    sf::Vector2f Position;
    
    std::string TextureName; // Original texture name
protected:
    bool inAir;
    Map* map;
    TypeId Type;
    Game* game;
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif