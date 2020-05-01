//
// Created by School on 4/28/20.
//

#include "mylibrary/GameWorld.h"

#include <mylibrary/GameBody.h>

#include "mylibrary/ConversionUtils.h"

GameWorld::GameWorld() {
  // Define the gravity vector.
  b2Vec2 gravity(0.0f, -10.0f);

  // Construct a world object, which will hold and simulate the rigid bodies.
  world.SetGravity(gravity);

}

void GameWorld::CreateBody(b2BodyDef body) {
  CreateBody(body, 50.0f, 10.0f, b2Vec2(0, -10));

}


void GameWorld::CreateBody(b2BodyDef bodyDef, float width, float height, b2Vec2 position) {
  b2Body* body = world.CreateBody(&bodyDef);
  GameBody newBody(body, position, width, height);
  bodies.push_back(newBody);
  b2PolygonShape box;
  box.SetAsBox(width, height);
  body->CreateFixture(&box, 0.0);

}

void GameWorld::Step(float32 timeStep, int32 velocityIterations, int32 positionIterations) {
  world.Step(timeStep, velocityIterations, positionIterations);
}

void GameWorld::draw() {
  for (std::vector<GameBody>::iterator iter = bodies.begin(); iter != bodies.end(); iter++) {
    iter->draw();
  }
}