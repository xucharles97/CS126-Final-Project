//
// Created by School on 4/28/20.
//

#ifndef FINALPROJECT_GAMEWORLD_H
#define FINALPROJECT_GAMEWORLD_H

#include <Box2D/Box2D.h>

#include <vector>

#include "ContactListener.h"
#include "GameBody.h"
#include "LevelMaker.h"
#include "PlayerBody.h"

class GameWorld {
 public:
  GameWorld();
  //add a body to the bodies vector
  //initialize its fixture
  //shape is box by default
  void CreateBody(b2BodyDef body);
  void CreateBody(float width, float height, b2Vec2 position);
  void CreateBody(float width, float height, float xCoord, float yCoord);
  void CreateBody(float width, float height, float xCoord, float yCoord, float red, float green, float blue);
  void Step(float32 timeStep, int32 velocityIterations, int32 positionIterations);
  LevelMaker::GameState Step(bool left, bool right, bool up, bool down);
  void draw();
  PlayerBody getPlayer();
  void setPlayer(float posX, float posY);
  std::vector<GameBody> bodies;
  void setEndPoint(float xCoord, float yCoord);
  bool playerAtEnd();
  void setWorldBottom(float newBottom);
  bool playerFellThroughPit();

 private:
  b2Vec2 gravity;
  b2World world = b2World(b2Vec2());
  PlayerBody player;
  b2Body* playerBody;
  float32 timeStep;
  int32 velocityIterations;
  int32 positionIterations;
  ContactListener contactListener;
  b2Vec2 endPoint;
  float worldBottom; //in physics form





};

#endif  // FINALPROJECT_GAMEWORLD_H
