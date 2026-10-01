// src/Board.cpp
//
// Definition of what is declared in Board.h.
// S04: rendering is now done with Raylib rectangles and text.

#include "Board.h"
#include "raylib.h"
#include <string>

// World constants (pixel-based)
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int PLAYER_SIZE = 40;

const float PLAYER_X = 120.0f;
const float GROUND_Y = 500.0f - PLAYER_SIZE;
const float TOP_Y = GROUND_Y - 120.0f;

const float SPEED = 300.0f;

const int LIVES_INIT = 3;

void displayState(const Position& player,
                  const std::vector<Position>& obstacles,
                  int score,
                  int lives) {

    // Ground (horizontal band)
    DrawRectangle(0,
                  (int)GROUND_Y + PLAYER_SIZE,
                  SCREEN_WIDTH,
                  SCREEN_HEIGHT - ((int)GROUND_Y + PLAYER_SIZE),
                  DARKGREEN);

    // Obstacles
    for (const Position& obs : obstacles) {
        DrawRectangle((int)obs.x, (int)obs.y,
                      PLAYER_SIZE, PLAYER_SIZE,
                      DARKGRAY);
    }

    // Player
    DrawRectangle((int)player.x, (int)player.y,
                  PLAYER_SIZE, PLAYER_SIZE,
                  RED);

    // Score + lives
    DrawText(("Score: " + std::to_string(score)).c_str(),
             10, 10, 20, BLACK);

    DrawText(("Lives: " + std::to_string(lives)).c_str(),
             SCREEN_WIDTH - 120, 10, 20, BLACK);
}
