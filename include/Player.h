// include/Player.h
//
// Player: the player logic.
//   - handleInput: reacts to keyboard (jump, quit)
//   - updateJump: manages landing after a delay
//   - checkCollision: pixel-based overlap test
//
// Needs Position from Board.h.

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Board.h"

// Input: SPACE to jump, ESC to quit.
// Returns true if the player wants to quit.
bool handleInput(Position& player, float& jumpTimer);

// Landing after jump (S04)
void updateJump(Position& player, float& jumpTimer, float dt);

// Pixel-based collision detection
bool checkCollision(const Position& player,
                    const std::vector<Position>& obstacles);

#endif  // PLAYER_H
