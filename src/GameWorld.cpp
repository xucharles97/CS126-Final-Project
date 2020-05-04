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

  b2BodyDef playerDef;
  playerDef.type = b2_dynamicBody;
  playerDef.position.Set(400.0f, 100.0f);

  b2Body* body = world.CreateBody(&playerDef);
  GameBody player(body, 5.0f, 5.0f);


//  player.type = b2_dynamicBody;
//  player.position.Set(400.0f, 100.0f);
//  playerBody = world.CreateBody(&player);
//
//  dynamicBox.SetAsBox(1.0f, 1.0f);
//
//  fixtureDef.shape = &dynamicBox;
//  fixtureDef.density = 1.0f;
//  fixtureDef.friction = 0.3f;
//  playerBody->CreateFixture(&fixtureDef);


}

void GameWorld::CreateBody(b2BodyDef body) {
  CreateBody(body, 100.0f, 50.0f, body.position);

}


void GameWorld::CreateBody(b2BodyDef bodyDef, float width, float height, b2Vec2 position) {
  std::cout << "GameWorld 27" << std::endl;
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
  for (auto iter = bodies.begin(); iter != bodies.end(); iter++) {
    iter->draw();
  }
  player.draw();
  //vec2 position(playerBody->GetPosition().x, playerBody->GetPosition().y);
//  vec2 position(player.position.x, player.position.y);
//
//  std::cout << "Player position: (" << position.x << ", " << position.y << ")" << std::endl;
//  cinder::gl::color(1, 0, 0);
//  //TODO: Figure out why the player isn't getting drawn
//  Rectf rect(position.x + 5, position.y - 5, position.x + 5,position.y + 5);
//  gl::drawSolidRect(rect);
}

//void GameWorld::addPlayer(b2BodyDef newPlayer) {
//  newPlayer.type = b2_dynamicBody;
//  b2Body* newPlayerBody = world.CreateBody(&newPlayer);
//  b2PolygonShape newPolygon;
//  newPolygon.SetAsBox(5.0f, 5.0f);
//  b2FixtureDef newFixture;
//  newFixtu
//}
