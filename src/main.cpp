#include "raylib-cpp.hpp"
#include <vector>

#include "world.h"
#include "worldgen.h"
#include "player.h"

int main() {
    raylib::Color background(RAYWHITE);
    raylib::Window w(1920, 1080, "Among Blocks");

    raylib::Camera camera(
            raylib::Vector3(4.0f, 2.0f, 4.0f),
            raylib::Vector3(0.0f, 1.8f, 0.0f),
            raylib::Vector3(0.0f, 1.0f, 0.0f),
            60.0f,
            CAMERA_PERSPECTIVE);
    camera.SetMode(CAMERA_FIRST_PERSON);

    raylib::Texture2D textures[] = {
        raylib::Texture2D ("../assets/textures/stone.png"), // this one is actually air
        raylib::Texture2D ("../assets/textures/stone.png"),
        raylib::Texture2D ("../assets/textures/box.png"),
    };

    SetTargetFPS(60);

    World world = WorldGen::test1();
    std::vector<Player> players;
    players.push_back(Player(BLACK, 10, 1, 10));
    players.push_back(Player(RED, 11, 1, 11));
    players.push_back(Player(YELLOW, 10, 1, 11));

    // Main game loop
    Vector3 pos;
    while (!w.ShouldClose()) {
        camera.Update();
        BeginDrawing();
        background.ClearBackground();
        camera.BeginMode3D();

        for (pos.y = 0.5; pos.y < WORLD_HEIGHT; pos.y++) {
            for (pos.z = 0.5; pos.z < WORLD_DEPTH; pos.z++) {
                for (pos.x = 0.5; pos.x < WORLD_WIDTH; pos.x++) {
                    int tid = world.getBlock(pos.x, pos.y, pos.z);
                    if (tid) {
                        textures[tid].Draw(pos, 1, 1, 1, RAYWHITE);
                    }
                }
            }
        }

        for (Player p : players) {
            // TODO: use this line, not the next
            // p.pos.DrawCylinder(PLAYER_RADII-0.1, PLAYER_RADII, PLAYER_HEIGHT, PLAYER_RES, p.getColor());
            DrawCylinder(p.pos, PLAYER_RADII-0.1, PLAYER_RADII, PLAYER_HEIGHT, PLAYER_RES, p.getColor());
        }

        EndMode3D();
        EndDrawing();
    }

    return 0;
}
