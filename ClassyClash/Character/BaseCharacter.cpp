#include "BaseCharacter.h"

BaseCharacter::BaseCharacter() {

}

void BaseCharacter::undoMovement() {
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec() {
    return Rectangle{
        screenPos.x,
        screenPos.y,
        scale * width,
        scale * height};
}