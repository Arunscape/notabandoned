#pragma once

#include "raylib-cpp.hpp"
#include "player.h"

class Controller {
    raylib::Vector3 pos;
    raylib::Camera3D& camera;

    float yaw;
    float pitch;

  public:
    Controller(raylib::Camera3D& c);
    ~Controller();

    void update(float delta);
};
