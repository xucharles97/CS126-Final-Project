//
// Created by School on 5/5/20.
//

#include "mylibrary/PlayerBody.h"

PlayerBody::PlayerBody() {
  color = {1, 0, 0};
  numJumps = 2;
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
}



void PlayerBody::Jump() {}
void PlayerBody::MoveLeft() {}
void PlayerBody::MoveRight() {}

b2Vec2 PlayerBody::GetPosition() {
  std::cout << "PlayerBody Position: (" << this->body->GetPosition().x << ", " << this->body->GetPosition().y << ")" << std::endl;
  return this->body->GetPosition();
}

void PlayerBody::SetPosition(b2Vec2 newPosition) {
  this->position = newPosition;
}

void PlayerBody::SetPosition(float newX, float newY) {
  this->position.x = newX;
  this->position.y = newY;
}
