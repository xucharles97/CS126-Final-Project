// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/Color.h>
#include <cinder/app/App.h>
#include <mylibrary/LevelOne.h>

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "mylibrary/ConversionUtils.h"
#include "mylibrary/GameBody.h"
#include "mylibrary/GameWorld.h"
#include "mylibrary/LevelMaker.h"

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

  LevelOne levelOne;
//  levelOne.LoadLevel();
  currentLevel = &levelOne;
  currentLevel->LoadLevel();

  inJumpCooldown = false;
  timeUntilNextJump = 0;
}

void MyApp::update() {
//  cout << "update" << std::endl;
  if (timeUntilNextJump > 0) {
    timeUntilNextJump--;
  }

  state = currentLevel->update(leftPressed, rightPressed, upPressed, downPressed);

  upPressed = false;

}

void MyApp::draw() {
  cinder::gl::clear();
  if (state == LevelMaker::GameState::FINISHED_LEVEL || state == LevelMaker::GameState::ONGOING) {
    currentLevel->draw();
  }

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
