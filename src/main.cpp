#include "raylib-cpp.hpp"

int main() {

	int screenWidth = 800;
	int screenHeight = 450;
	raylib::Color background(RAYWHITE);
	raylib::Color textColor(LIGHTGRAY);
	raylib::Window w(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	// Main game loop
	while (!w.ShouldClose()) {

		// Draw
		BeginDrawing();
		background.ClearBackground();
		textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);

		EndDrawing();
	}

	return 0;
}
