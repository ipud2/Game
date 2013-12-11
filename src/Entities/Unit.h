#ifndef UNIT_H
#define UNIT_H

#include <SFML/System/Time.hpp>
#include "Entity.h"

class Game;

class Unit : public Entity
{
public:
    Unit(Game* _game, std::string model);
    virtual ~Unit();

    virtual void Update(sf::Time const diff) override;

    virtual void LoadMoveTexture(int type) override { }

    virtual void Jump();
    virtual bool IsJumping() const { return jumping; }

    int HealthPoints;
    bool jumping;
};
#endif