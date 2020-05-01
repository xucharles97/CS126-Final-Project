// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <mylibrary/GameWorld.h>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  b2Vec2 gravity;
  b2World world;
  void drawWorld(GameWorld& world);
  GameWorld demo;
 private:
  float32 timeStep;
  int32 velocityIterations;
  int32 positionIterations;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
