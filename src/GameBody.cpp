//
// Created by School on 4/30/20.
//

#include "mylibrary/GameBody.h"
#include "cinder/gl/gl.h"
#include "mylibrary/ConversionUtils.h"
using cinder::Color;

GameBody::GameBody(b2Body* body, b2Vec2 position, float bodyWidth, float bodyHeight) {
  this->position = position;
  this->width = bodyWidth;
  this->height = bodyHeight;
  this->body = body;
  shape.SetAsBox(width, height);
  this->body->CreateFixture(&shape, 0.0f);
  color = {0, 1, 0};
}

void GameBody::draw() {
  vec2 pos(body->GetPosition().x, body->GetPosition().y);

//  glPushMatrix();
//  gl::translate(pos);
//  std::cout << "Body position: (" << pos.x << ", " << pos.y << ")" << std::endl;
  cinder::gl::color(color.r, color.g, color.b);
  Rectf rect(pos.x - width, pos.y - height, pos.x + width, pos.y + height);
  gl::drawSolidRect(rect);

}
b2Vec2 GameBody::getPosition() { return position; }

float GameBody::getWidth() { return width; }

float GameBody::getHeight() { return height; }

GameBody::GameBody(b2Body* body, float bodyWidth, float bodyHeight) {
  if (body->GetType() == b2_dynamicBody) {

    shape.SetAsBox(bodyWidth, bodyHeight);
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    this->body = body;
    this->body->CreateFixture(&fixtureDef);

  } else {
    GameBody(body, body->GetPosition(), width, height);
  }
}

GameBody::GameBody() {
  color = {0, 1, 0};
}
