//
// Created by School on 4/28/20.
//

#include "mylibrary/GameWorld.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>
#include <mylibrary/GameBody.h>

#include "mylibrary/ConversionUtils.h"

GameWorld::GameWorld() {
  // Define the gravity vector.
  b2Vec2 gravity(0.0f, 10.0f);

  // Construct a world object, which will hold and simulate the rigid bodies.
  world.SetGravity(gravity);
  timeStep = 1.0f / 60.0f;
  velocityIterations = 6;
  positionIterations = 2;


}

void GameWorld::CreateBody(b2BodyDef body) {
  CreateBody(100.0f, 50.0f, body.position);

}


void GameWorld::CreateBody(float width, float height, b2Vec2 position) {
  b2BodyDef bodyDef;
  bodyDef.position.Set(Conversions::toPhysics(position).x, Conversions::toPhysics(position).y);
  b2Body* body = world.CreateBody(&bodyDef);
  GameBody newBody(body, Conversions::toPhysics(position), Conversions::dimensionsToPhysics(width), Conversions::dimensionsToPhysics(height));
  bodies.push_back(newBody);
  b2PolygonShape box;
  box.SetAsBox(newBody.getWidth(), newBody.getHeight());
  body->CreateFixture(&box, 0.0);

}

void GameWorld::Step(float32 timeStep, int32 velocityIterations, int32 positionIterations) {
  world.Step(timeStep, velocityIterations, positionIterations);
  std::cout << "Player position in GameWorld: (" << playerBody->GetPosition().x << ", " << playerBody->GetPosition().y << ")" << std::endl;

}

void GameWorld::Step(bool left, bool right, bool up, bool down) {
  player.processDirectionalInput(left, right, up, down);
  world.Step(timeStep, velocityIterations, positionIterations);
}

void GameWorld::draw() {
  for (auto iter = bodies.begin(); iter != bodies.end(); iter++) {
    iter->draw();
  }

}
void GameWorld::setPlayer(float posX, float posY) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(Conversions::toPhysics(posX), Conversions::toPhysics(posY));
  playerBody = world.CreateBody(&bodyDef);

//  // Define another box shape for the player
//  b2PolygonShape dynamicBox;
//  dynamicBox.SetAsBox(50.0f, 50.0f);
//
//  b2FixtureDef fixtureDef;
//  fixtureDef.shape = &dynamicBox;
//  fixtureDef.density = 1.0f;
//  fixtureDef.friction = 0.3f;
//  player->CreateFixture(&fixtureDef);

  player = PlayerBody (playerBody, Conversions::dimensionsToPhysics(50.0f), Conversions::dimensionsToPhysics(50.0f));
  std::cout << "made player!" << std::endl;
}

PlayerBody GameWorld::getPlayer() {
  return player;
}

//void GameWorld::addPlayer(b2BodyDef newPlayer) {
//  newPlayer.type = b2_dynamicBody;
//  b2Body* newPlayerBody = world.CreateBody(&newPlayer);
//  b2PolygonShape newPolygon;
//  newPolygon.SetAsBox(5.0f, 5.0f);
//  b2FixtureDef newFixture;
//  newFixtu
//}
