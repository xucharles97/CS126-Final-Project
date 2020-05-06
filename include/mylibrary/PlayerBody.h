//
// Created by School on 5/5/20.
//

#ifndef FINALPROJECT_PLAYERBODY_H
#define FINALPROJECT_PLAYERBODY_H

#include "GameBody.h"

class PlayerBody : public GameBody {
 public:
  //Constructors
  PlayerBody();
  PlayerBody(b2Body* body, float width, float height);

  enum direction {DIR_LEFT, DIR_RIGHT, DIR_STOP};

  void processDirectionalInput(bool leftInput, bool rightInput, bool upInput, bool downInput);
  void jump();
  void moveLeft();
  void moveRight();
  void stopHorizontally();


  void touchedGround();
  void leftGround();



  b2Vec2 getPhysicsPosition();
  ci::vec2 getScreenPosition();

  void setPosition(b2Vec2 newPosition);
  void setPosition(float newX, float newY);



 private:
  int maxJumps;
  int numJumps;
  bool isTouchingGround;
  b2Fixture* footSensor;
  float maxHorizontalSpeed = 6.0f;
  direction currentDirection;
  b2PolygonShape footShape;
  b2FixtureDef footFixtureDef;


};

#endif  // FINALPROJECT_PLAYERBODY_H
