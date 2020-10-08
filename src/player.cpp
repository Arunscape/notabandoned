#include "player.h"

Player::Player(Color ncolor, int x, int y, int z) {
    color = ncolor;
    pos.x = x;
    pos.y = y;
    pos.z = z;
}

Player::~Player() {
}

Color Player::getColor() {
    return color;
}
