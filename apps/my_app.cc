// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include "mylibrary/GameBody.h"
#include "mylibrary/GameWorld.h"

namespace myapp {

using cinder::app::KeyEvent;
using std::cout;

MyApp::MyApp() :
  gravity{0.0f, -10.0f},
  world{gravity},
  width{800.0f},
  height{800.0f},
  timeStep{1.0f / 60.0f},
  velocityIterations{6},
  positionIterations{2} {}


void MyApp::setup() {

  //TODO: Refactor into classes specific to a given level (use polymorphism)
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(width / 2, height - 50);
  demo.CreateBody(groundBodyDef, width, height / 8, groundBodyDef.position);

  b2BodyDef topRight;
  topRight.position.Set(width, 50);
  demo.CreateBody(topRight, 25, 25, topRight.position);

  b2BodyDef topLeft;
  topRight.position.Set(0, 50);
  demo.CreateBody(topRight, 25, 25, topLeft.position);
}

void MyApp::update() {
//  cout << "update" << std::endl;
  demo.Step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {
  drawWorld(demo);
//  cinder::gl::drawSolidRect(Rectf(100.0f, 100.0f, 150.0f, 150.0f));
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::drawWorld(GameWorld& gameWorld) {
  gameWorld.draw();
}

}  // namespace myapp
