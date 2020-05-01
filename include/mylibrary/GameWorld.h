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
  //add a body to the bodies vector
  //initialize its fixture
  //shape is box by default
  void CreateBody(b2BodyDef body);
  void CreateBody(b2BodyDef body, float width, float height);
  void Step(float32 timeStep, int32 velocityIterations, int32 positionIterations);
  std::vector<b2Body*> bodies;

 private:
  b2Vec2 gravity;
  b2World world = b2World(b2Vec2());


};

#endif  // FINALPROJECT_GAMEWORLD_H
