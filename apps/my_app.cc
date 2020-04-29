// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <Box2D/Box2D.h>
#include "mylibrary/GameWorld.h"

namespace myapp {

using cinder::app::KeyEvent;
using std::cout;

MyApp::MyApp() :
  gravity{0.0f, -10.0f},
  world{gravity} {}


void MyApp::setup() {
  // Define the ground body.


}

void MyApp::update() { }

void MyApp::draw() { }

void MyApp::keyDown(KeyEvent event) { }

void MyApp::drawWorld(const GameWorld& world) {

}

}  // namespace myapp
