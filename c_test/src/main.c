#include "raylib.h"

#define UNIT 1

struct cube_t {
    Vector3 pos;
    int id;
};

int make_blocks(struct cube_t* cubes) {
    struct cube_t hardcubes[] = {
        {{2, 1, 0}, 1},
        {{2, 2, 0}, 1},
        {{2, 3, 0}, 1},

        {{2, 1, 1}, 1},
        {{2, 2, 1}, 1},

        {{2, 1, 2}, 1},

    };
    int cubecount = sizeof(hardcubes) / sizeof(struct cube_t);

    int i;
    for (i = 0;  i < cubecount; i++) {
        cubes[i] = hardcubes[i];
    }

    int bound = 16;
    for (int x = -bound; x < bound; x++) {
        for (int z = -bound; z < bound; z++) {
            cubes[i++] = (struct cube_t) {{x, 0, z}, 0};
        }
    }

    return i;
}

int main(void) {
    InitWindow(1920, 1080, "among blocks");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.target = (Vector3){ 100.0f, 100.0f, 100.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;


    Texture2D textures[] = {
        LoadTexture("assets/textures/stone.png"),
        LoadTexture("assets/textures/box.png")
    };

    struct cube_t cubes[10000];
    int cubecount = make_blocks(cubes);


    SetCameraMode(camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera);

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                for (int i = 0; i < cubecount; i++) {
                    DrawCubeTexture(textures[cubes[i].id], cubes[i].pos, 1, 1, 1, RAYWHITE);
                }
            EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
