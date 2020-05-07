//
// Created by School on 5/6/20.
//

#include "mylibrary/LevelMaker.h"

LevelMaker::LevelMaker() {
  LevelMaker(800.0f);
}

LevelMaker::LevelMaker(float screenSize) {
  this->screenSize = screenSize;

  worldBottom = screenSize;
  level.setWorldBottom(worldBottom);
}

LevelMaker::GameState LevelMaker::update(bool leftInput, bool rightInput, bool upInput, bool downInput) {
  return level.Step(leftInput, rightInput, upInput, downInput);
}

void LevelMaker::draw() {
  level.draw();
}
void LevelMaker::setNextLevel(LevelMaker* nextLevel) {
  this->nextLevel = nextLevel;
}
void LevelMaker::LoadLevel() {}
LevelMaker* LevelMaker::getNextLevel() { return nextLevel; }
