#include "raylib-cpp.hpp"
#include <vector>

struct Cube {
    Vector3 pos;
    int id;

    Cube(float x, float y, float z, int nid) {
        pos = (Vector3){x, y, z};
        id = nid;
    }
};

void make_blocks(std::vector<Cube>& cubes) {
    cubes.push_back(Cube(2, 1, 0, 1));
    cubes.push_back(Cube(2, 2, 0, 1));
    cubes.push_back(Cube(2, 3, 0, 1));
    cubes.push_back(Cube(2, 1, 1, 1));
    cubes.push_back(Cube(2, 2, 1, 1));
    cubes.push_back(Cube(2, 1, 2, 1));


    int bound = 16;
    for (int x = -bound; x < bound; x++) {
        for (int z = -bound; z < bound; z++) {
            cubes.push_back(Cube(x, 0, z, 0));
        }
    }

}

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
        raylib::Texture2D ("../assets/textures/stone.png"),
        raylib::Texture2D  ("../assets/textures/box.png")
    };

	SetTargetFPS(60);

    std::vector<Cube> cubes;
    make_blocks(cubes);

	// Main game loop
	while (!w.ShouldClose()) {
        camera.Update();
		BeginDrawing();
        background.ClearBackground();
        camera.BeginMode3D();

        for (Cube c : cubes) {
            textures[c.id].Draw(c.pos, 1, 1, 1, RAYWHITE);
        }

        EndMode3D();
		EndDrawing();
	}

	return 0;
}
