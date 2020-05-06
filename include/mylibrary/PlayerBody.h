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



  b2Vec2 getPosition();
  void setPosition(b2Vec2 newPosition);
  void setPosition(float newX, float newY);


 private:
  int numJumps;
  float maxHorizontalSpeed = 50.0f;
  direction currentDirection;


};

#endif  // FINALPROJECT_PLAYERBODY_H
