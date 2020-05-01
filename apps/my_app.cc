// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <Box2D/Box2D.h>
#include "mylibrary/GameWorld.h"
#include "mylibrary/GameBody.h"

namespace myapp {

using cinder::app::KeyEvent;
using std::cout;

MyApp::MyApp() :
  gravity{0.0f, -10.0f},
  world{gravity},
  timeStep{1.0f / 60.0f},
  velocityIterations{6},
  positionIterations{2} {}


void MyApp::setup() {

  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -10.0f);
  demo.CreateBody(groundBodyDef);
}

void MyApp::update() {
  demo.Step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {
  drawWorld(demo);
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::drawWorld(GameWorld& gameWorld) {
  gameWorld.draw();
}

}  // namespace myapp
