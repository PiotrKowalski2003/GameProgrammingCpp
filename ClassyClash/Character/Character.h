#ifndef CLASSYCLASH_CHARACTER_H
#define CLASSYCLASH_CHARACTER_H

#include <raylib.h>
#include "BaseCharacter.h"

class Character : public BaseCharacter {
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
private:

};


#endif //CLASSYCLASH_CHARACTER_H