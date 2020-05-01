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
  timeStep{1.0f / 60.0f},
  velocityIterations{6},
  positionIterations{2} {}


void MyApp::setup() {
  cout << "setup" << std::endl;
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(100.0f, 100.0f);
  demo.CreateBody(groundBodyDef);
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
