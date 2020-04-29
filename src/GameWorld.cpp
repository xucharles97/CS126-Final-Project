//
// Created by School on 4/28/20.
//

#include "mylibrary/GameWorld.h"
#include "mylibrary/ConversionUtils.h"

GameWorld::GameWorld() {
  // Define the gravity vector.
  b2Vec2 gravity(0.0f, -10.0f);

  // Construct a world object, which will hold and simulate the rigid bodies.
  world.SetGravity(gravity);

}

void GameWorld::CreateBody(b2BodyDef &body) {
  bodyDefs.push_back(body);

}
