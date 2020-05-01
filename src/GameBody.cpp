//
// Created by School on 4/30/20.
//

#include "mylibrary/GameBody.h"
#include "cinder/gl/gl.h"
#include "mylibrary/ConversionUtils.h"
using cinder::Color;

GameBody::GameBody(b2Body* body, b2Vec2 position, float w, float h) {
  this->position = position;
  this->width = w;
  this->height = h;
  this->body = body;
  shape.SetAsBox(width, height);
  this->body->CreateFixture(&shape, 0.0f);
  color = {0, 0, 1};
}

void GameBody::draw() {
  vec2 pos = Conversions::toScreen(body->GetPosition());

//  glPushMatrix();
  gl::translate(pos);
  Rectf rect(-width, -height, width, height);
  gl::drawSolidRect(rect);
}