// include/Board.h
//
// Board: the "world" of the Runner.
//   - Position struct (shared across the whole project)
//   - world constants (pixel dimensions, reference positions)
//   - scene display (Raylib rectangles + text)
//
// S04: console grid replaced by pixel-based rendering.

#ifndef BOARD_H
#define BOARD_H

#include <vector>

// Pixel coordinates of objects.
struct Position {
    float x;
    float y;
};

// World constants (declared here, defined in Board.cpp)
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int PLAYER_SIZE;

extern const float PLAYER_X;
extern const float GROUND_Y;
extern const float TOP_Y;
extern const float SPEED;

extern const int LIVES_INIT;

// Draws the scene: ground, player, obstacles, score, lives.
void displayState(const Position& player,
                  const std::vector<Position>& obstacles,
                  int score,
                  int lives);

#endif  // BOARD_H
