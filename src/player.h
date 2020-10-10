#pragma once

#include "raylib-cpp.hpp"

#define PLAYER_HEIGHT 1.8f
#define PLAYER_RADII  0.45f
#define PLAYER_RES 16 /* How many slices for rendering cylinder*/

// the collision area of a player is a capsile (pill shape)
// two spheres and a cylinder basically.

// for rendering, they'll be a cylinder until someone makes a model

class Player {
    Color color;

  public:
    raylib::Vector3 pos;
    Player(Color color, int x, int y, int z);
    ~Player();
    Color getColor();
};
