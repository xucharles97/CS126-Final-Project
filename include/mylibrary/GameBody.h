//
// Created by School on 4/30/20.
//

#ifndef FINALPROJECT_GAMEBODY_H
#define FINALPROJECT_GAMEBODY_H

#include <Box2D/Box2D.h>
#include <cinder/Color.h>

using cinder::Color;

class GameBody {
 public:
  GameBody();
  GameBody(b2Body* body, b2Vec2 position, float width, float height);
  GameBody(b2Body* body, float width, float height);
  virtual void draw();
  b2Vec2 getPosition();
  float getWidth();
  float getHeight();

  //Need:
  //b2BodyDef w/ position vector
  //b2Body* from World.CreateBody
  //b2PolygonShape (box) w/ dimensions
  //Color
 protected:
  b2Vec2 position;
  b2Body* body;
  float width;
  float height;
  b2PolygonShape shape;
  b2FixtureDef fixtureDef;
  Color color;
};

#endif  // FINALPROJECT_GAMEBODY_H
