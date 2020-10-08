#include "raylib-cpp.hpp"
#include <vector>
#include <world/chunk.h>

#include "player.h"

class WorldGen : public World::ChunkLoader {
public:
    virtual ~WorldGen() {}
    virtual void request_chunk(const World::ChunkPos& chunk) override {
        World::ChunkPos origin = {0, 0};
        if (chunk == origin) {
            auto ch = std::make_unique<World::Chunk>(origin);

            ch->set_block({8, 1, 8}, 2);
            ch->set_block({8, 2, 8}, 2);
            ch->set_block({8, 3, 8}, 2);
            ch->set_block({8, 1, 8}, 2);
            ch->set_block({8, 2, 8}, 2);
            ch->set_block({8, 1, 8}, 2);

            int bound = 16;
            for (int x = 0; x < bound; x++) {
                for (int z = 0; z < bound; z++) {
                    ch->set_block({x, 0, z}, 1);
                }
            }
            chunk_manager().add_chunk(chunk, move(ch));
        } else {
            chunk_manager().add_chunk(chunk, nullptr);
        }
    }
};

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

    SetTargetFPS(60);

    World::ResourcePack resource_pack;
    resource_pack
        .set_block(0, std::make_unique<World::AirBlock>())
        .set_block(1, std::make_unique<World::PlainBlock>("../assets/textures/stone.png"))
        .set_block(2, std::make_unique<World::PlainBlock>("../assets/textures/box.png"));

    WorldGen worldgen;
    World::ChunkManager cm(resource_pack, worldgen);

    //World world = WorldGen::test1();
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

        cm.draw({0, 0}); //TODO follow player

        for (Player p : players) {
            // TODO: use this line, not the next
            // p.pos.DrawCylinder(PLAYER_RADII-0.1, PLAYER_RADII, PLAYER_HEIGHT, PLAYER_RES, p.getColor());
            DrawCylinder(p.pos, PLAYER_RADII-0.1, PLAYER_RADII, PLAYER_HEIGHT, PLAYER_RES, p.getColor());
        }

        EndMode3D();
        DrawFPS(0, 0);
        EndDrawing();
    }

    return 0;
}
