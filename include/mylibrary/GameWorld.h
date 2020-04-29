//
// Created by School on 4/28/20.
//

#ifndef FINALPROJECT_GAMEWORLD_H
#define FINALPROJECT_GAMEWORLD_H

#include <Box2D/Box2D.h>

#include <vector>

class GameWorld {
 public:
  GameWorld();
  void CreateBody(b2BodyDef &body);

 private:
  b2Vec2 gravity;
  b2World world;
  std::vector<b2BodyDef> bodyDefs;

};

#endif  // FINALPROJECT_GAMEWORLD_H
