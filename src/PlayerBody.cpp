//
// Created by School on 5/5/20.
//

#include "mylibrary/PlayerBody.h"

PlayerBody::PlayerBody() {
  color = {1, 0, 0};
  numJumps = 2;
  currentDirection = DIR_STOP;
}

PlayerBody::PlayerBody(b2Body* bodyInput, float bodyWidth, float bodyHeight) {
  bodyInput->SetType(b2_dynamicBody);
  width = bodyWidth;
  height = bodyHeight;
  this->body = bodyInput;
  shape.SetAsBox(width, height);
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;

  this->body->CreateFixture(&fixtureDef);

  color = {1, 0, 0};

  numJumps = 2;
  currentDirection = DIR_STOP;
}

void PlayerBody::processDirectionalInput(bool leftInput, bool rightInput,
                                         bool upInput, bool downInput) {
  std::cout << "up: " << std::to_string(upInput) << " down: " << std::to_string(downInput) << " left: " << std::to_string(leftInput) << " right: " << std::to_string(rightInput) << std::endl;

  if (upInput) {
    jump();
  }

  //Process right and left inputs
  //Right will always override left
  if (rightInput) {
    moveRight();
  } else if (leftInput) {
    moveLeft();
  } else {
    stopHorizontally();
  }

}

void PlayerBody::jump() {}
void PlayerBody::moveLeft() {
  b2Vec2 velocity = body->GetLinearVelocity();
  velocity.x = -1 * maxHorizontalSpeed;
  body->SetLinearVelocity(velocity);
  currentDirection = DIR_LEFT;
}
void PlayerBody::moveRight() {
  b2Vec2 velocity = body->GetLinearVelocity();
  velocity.x = maxHorizontalSpeed;
  body->SetLinearVelocity(velocity);
  currentDirection = DIR_RIGHT;
}

void PlayerBody::stopHorizontally() {
  b2Vec2 velocity = body->GetLinearVelocity();
  velocity.x *= .987;
//  velocity.x = 0;
  body->SetLinearVelocity(velocity);
  currentDirection = DIR_STOP;
}

b2Vec2 PlayerBody::getPosition() {
  std::cout << "PlayerBody Position: (" << this->body->GetPosition().x << ", " << this->body->GetPosition().y << ")" << std::endl;
  return this->body->GetPosition();
}

void PlayerBody::setPosition(b2Vec2 newPosition) {
  this->position = newPosition;
}

void PlayerBody::setPosition(float newX, float newY) {
  this->position.x = newX;
  this->position.y = newY;
}

