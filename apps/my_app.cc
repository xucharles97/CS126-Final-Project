// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/Color.h>
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

#include "mylibrary/GameBody.h"
#include "mylibrary/GameWorld.h"

namespace myapp {

using cinder::app::KeyEvent;
using std::cout;
using cinder::Color;
using cinder::Rectf;


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

  b2BodyDef top;
  top.position.Set(width / 2, 0);
  demo.CreateBody(top, width, 25, top.position);

  b2BodyDef left;
  left.position.Set(0, height / 2);
  demo.CreateBody(left, 25, height, left.position);

  b2BodyDef right;
  right.position.Set(width - 50, height / 2);
  demo.CreateBody(right, 25, height, right.position);

  demo.setPlayer(125.0f, 125.0f);
}

void MyApp::update() {
//  cout << "update" << std::endl;
  demo.Step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {
  cinder::gl::clear();
  drawWorld(demo);

  cinder::gl::color(1, 0, 0);
  cinder::vec2 position(demo.getPlayer().GetPosition().x, demo.getPlayer().GetPosition().y);
  cout << "Player position: (" << position.x << ", " << position.y << ")" << std::endl;
  Rectf rect(position.x + 50, position.y + 50, position.x, position.y);
  cinder::gl::drawSolidRect(rect);
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::drawWorld(GameWorld& gameWorld) {
  gameWorld.draw();
}

}  // namespace myapp
