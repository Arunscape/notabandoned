#include "controller.h"
#include "raylib-cpp.hpp"
#include <math.h>
#include <iostream>

constexpr float SPEED = 5.0;
constexpr float CAMERA_MOUSE_MOVE_SENSITIVITY = 0.005;
constexpr float CAMERA_FREE_PANNING_DIVIDER = 5.1;

Controller::Controller(raylib::Camera3D& c) : camera(c) {
    pos = (raylib::Vector3){0.0, 2.0, 0.0};
    yaw = 0;
    pitch = 0;
    DisableCursor();
}
Controller::~Controller() {}

void Controller::update(float delta) {
    static Vector2 previousMousePosition = { 0.0f, 0.0f };

    bool up = IsKeyDown(KEY_W);
    bool down = IsKeyDown(KEY_S);
    bool left = IsKeyDown(KEY_A);
    bool right = IsKeyDown(KEY_D);

    Vector2 mousePositionDelta = { 0.0f, 0.0f };
    Vector2 mousePosition = GetMousePosition();
    mousePositionDelta.x = mousePosition.x - previousMousePosition.x;
    mousePositionDelta.y = mousePosition.y - previousMousePosition.y;
    previousMousePosition = mousePosition;

    yaw   += mousePositionDelta.x * -CAMERA_MOUSE_MOVE_SENSITIVITY;
    pitch += mousePositionDelta.y *  CAMERA_MOUSE_MOVE_SENSITIVITY;

    float z = 0;
    float x = 0;
    if (up && !down) {
        z += SPEED * delta;
    } else if (down && !up) {
        z -= SPEED * delta;
    } else if (left && !right) {
        x += SPEED * delta;
    } else if (right && !left) {
        x -= SPEED * delta;
    }

    pos.x += cos(yaw) * x + sin(yaw) * z;
    pos.z += cos(yaw) * z - sin(yaw) * x;

    camera.SetPosition(pos);

    Matrix translation = MatrixTranslate(0, 0, (1/CAMERA_FREE_PANNING_DIVIDER));
    Matrix rotation = MatrixRotateXYZ((Vector3){ PI*2 - pitch, PI*2 - yaw, 0 });
    Matrix transform = MatrixMultiply(translation, rotation);

    camera.target.x = camera.position.x - transform.m12;
    camera.target.y = camera.position.y - transform.m13;
    camera.target.z = camera.position.z - transform.m14;

}
