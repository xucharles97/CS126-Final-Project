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
  position = bodyInput->GetPosition();
  width = bodyWidth;
  height = bodyHeight;
  shape.SetAsBox(width, height);
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);

  color = {1, 0, 0};

  numJumps = 2;
}



void PlayerBody::Jump() {}
void PlayerBody::MoveLeft() {}
void PlayerBody::MoveRight() {}

