//
// Created by School on 5/6/20.
//

#ifndef FINALPROJECT_LEVELMAKER_H
#define FINALPROJECT_LEVELMAKER_H

#include <Box2D/Common/b2Math.h>

#include "GameWorld.h"

class LevelMaker {
 public:
  LevelMaker();
  LevelMaker(float screenSize);

  enum GameState {ONGOING, GAME_OVER, FINISHED_LEVEL};

  GameState update();
  LevelMaker* getNextLevel();

  virtual void LoadLevel();
  virtual void draw();

  void setNextLevel(LevelMaker &nextLevel);

 private:
  LevelMaker* nextLevel;
  float bottomBoundary;
  b2Vec2 spawnPoint;
  b2Vec2 endPoint;
  GameWorld level;
  float screenSize;


};

#endif  // FINALPROJECT_LEVELMAKER_H
