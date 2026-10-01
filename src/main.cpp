// src/main.cpp
//
// Runner orchestrator: in S04, the console loop is replaced by
// a Raylib window and a real-time game loop.
// Board handles the rendering, Player handles the logic.
// main only orchestrates the world and the loop.

#include "raylib.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <algorithm>


int main() {

    // --- Window setup (S04) ---
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Runner CS.1109");
    SetTargetFPS(60);

    // --- World state (player, obstacles, score, lives) ---
    Position player{ PLAYER_X, GROUND_Y };
    std::vector<Position> obstacles;

    int score = 0;
    int lives = LIVES_INIT;

    float jumpTimer = 0.0f;
    float spawnTimer = 0.0f;
    float hitCooldown = 0.0f;

    // --- Main loop: runs until ESC or window close ---
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();   // duration of the previous frame

        // --- Input (Player module) ---
        if (handleInput(player, jumpTimer)) {
            break; // ESC pressed
        }

        updateJump(player, jumpTimer, dt);

        // --- Obstacle scrolling (pixels per second) ---
        for (auto& obs : obstacles) {
            obs.x -= SPEED * dt;
        }

        // Remove obstacles that left the screen
        obstacles.erase(
            std::remove_if(obstacles.begin(), obstacles.end(),
                           [](const Position& p) {
                               return p.x + PLAYER_SIZE < 0;
                           }),
            obstacles.end()
        );

        // --- Obstacle spawning (every 1.5s) ---
        spawnTimer += dt;
        if (spawnTimer >= 1.5f) {
            spawnTimer = 0.0f;

            float y = (GetRandomValue(0, 1) == 0) ? GROUND_Y : TOP_Y;
            obstacles.push_back({ SCREEN_WIDTH, y });
        }

        // --- Collision detection (Player module) ---
        if (hitCooldown > 0.0f) {
            hitCooldown -= dt;
        } else {
            if (checkCollision(player, obstacles)) {
                lives -= 1;
                hitCooldown = 0.5f;
            }
        }

        if (lives <= 0) {
            break;
        }

        score += 1;

        // --- Rendering (Board module) ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        displayState(player, obstacles, score, lives);

        EndDrawing();
    }

    // --- End screen ---
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("GAME OVER", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 20, 40, RED);
    EndDrawing();

    CloseWindow();
    return 0;
}
