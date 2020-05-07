// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/Color.h>
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

#include "mylibrary/GameBody.h"
#include "mylibrary/GameWorld.h"
#include "mylibrary/ConversionUtils.h"

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
  positionIterations{2},
  jumpCooldown{10} {}


void MyApp::setup() {
  upPressed, downPressed, leftPressed, rightPressed = false;

  //TODO: Refactor into classes specific to a given level (use polymorphism)
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(width / 2, height - 75);
  demo.CreateBody(width, 150, groundBodyDef.position);

//  b2BodyDef top;
//  top.position.Set(width / 2, 0);
//  demo.CreateBody(width, 25, top.position);
//
  b2BodyDef left;
  left.position.Set(0, height / 2);
  demo.CreateBody(1, height, left.position);
//
//  b2BodyDef right;
//  right.position.Set(width - 50, height / 2);
//  demo.CreateBody(right, 25, height, right.position);
//
  demo.setPlayer(125.0f, height - 150);

  inJumpCooldown = false;
  timeUntilNextJump = 0;
}

void MyApp::update() {
//  cout << "update" << std::endl;
  if (timeUntilNextJump > 0) {
    timeUntilNextJump--;
  }

  demo.Step(leftPressed, rightPressed, upPressed, downPressed);

  upPressed = false;

}

void MyApp::draw() {
  cinder::gl::clear();
  drawWorld(demo);

//  cinder::gl::color(1, 0, 0);
//  cinder::vec2 position = demo.getPlayer().getScreenPosition();
//  cout << "Player position: (" << position.x << ", " << position.y << ")" << std::endl;
//  float widthToDraw = Conversions::dimensionsToScreen(demo.getPlayer().getWidth()) / 2;
//  float heightToDraw = Conversions::dimensionsToScreen(demo.getPlayer().getHeight()) / 2;
//  Rectf rect(position.x - widthToDraw, position.y - heightToDraw, position.x + widthToDraw, position.y + heightToDraw);
//  cinder::gl::drawSolidRect(rect);
}

void MyApp::keyDown(KeyEvent event) {
//  upPressed, downPressed, leftPressed, rightPressed = false;
//  cout << "keyDown code: " << std::to_string(event.getChar()) << std::endl;

  int code = event.getCode();
  if (code == KeyEvent::KEY_UP || code == KeyEvent::KEY_w) {
      if (timeUntilNextJump <= 0) {
        upPressed = true;
        timeUntilNextJump = jumpCooldown;
      }
  }

  if (code == KeyEvent::KEY_DOWN || code == KeyEvent::KEY_s) {
    downPressed = true;
  }

  if (code == KeyEvent::KEY_LEFT || code == KeyEvent::KEY_a) {
    leftPressed = true;
  }

  if (code == KeyEvent::KEY_RIGHT || code == KeyEvent::KEY_d) {
    rightPressed = true;
  }

}

void MyApp::keyUp(KeyEvent event) {
  int code = event.getCode();
  if (code == KeyEvent::KEY_UP || code == KeyEvent::KEY_k) {
    upPressed = false;
  }

  if (code == KeyEvent::KEY_DOWN || code == KeyEvent::KEY_j) {
    downPressed = false;
  }

  if (code == KeyEvent::KEY_LEFT || code == KeyEvent::KEY_a) {
    leftPressed = false;
  }

  if (code == KeyEvent::KEY_RIGHT || code == KeyEvent::KEY_s) {
    rightPressed = false;
  }
}

void MyApp::drawWorld(GameWorld & gameWorld) { gameWorld.draw(); }

}  // namespace myapp
