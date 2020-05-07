//
// Created by School on 5/6/20.
//

#include "mylibrary/LevelOne.h"

LevelOne::LevelOne() {
  this->screenSize = 800.0f;

  worldBottom = screenSize;
  level.setWorldBottom(worldBottom);
//  LevelMaker(screenSize, newLevel);
  this->spawnPoint.x = 125.0f;
  this->spawnPoint.y = screenSize - 150;


  this->endPoint.x = screenSize - 125.0f;
  this->endPoint.y = screenSize - 125.0f;
}
void LevelOne::LoadLevel() {
  level.CreateBody(screenSize, 150, screenSize / 2, screenSize - 75);
  level.CreateBody(1, screenSize, -1, screenSize / 2);
  level.setEndPoint(endPoint.x, endPoint.y);
  level.setPlayer(spawnPoint.x, spawnPoint.y);
}
