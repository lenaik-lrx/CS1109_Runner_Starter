// src/Player.cpp
//
// Definition of what is declared in Player.h.
// S04: input uses Raylib keyboard, collision uses pixel overlap.

#include "Player.h"
#include "raylib.h"

bool handleInput(Position& player, float& jumpTimer) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        return true;
    }
    if (IsKeyPressed(KEY_SPACE) && player.y == GROUND_Y) {
        player.y = TOP_Y;
    }
    return false;
}

void updateJump(Position& player, float& jumpTimer, float dt) {
    if (player.y < GROUND_Y) {
        jumpTimer += dt;
        if (jumpTimer >= 0.5f) {
            player.y = GROUND_Y;
            jumpTimer = 0.0f;
        }
    }
}

bool checkCollision(const Position& player,
                    const std::vector<Position>& obstacles) {

    for (const Position& obs : obstacles) {
        bool overlapX = player.x < obs.x + PLAYER_SIZE &&
                        obs.x < player.x + PLAYER_SIZE;

        bool overlapY = player.y < obs.y + PLAYER_SIZE &&
                        obs.y < player.y + PLAYER_SIZE;

        if (overlapX && overlapY) {
            return true;
        }
    }
    return false;
}
