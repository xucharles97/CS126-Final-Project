//
// Created by School on 4/28/20.
//

#ifndef FINALPROJECT_CONVERSIONUTILS_H
#define FINALPROJECT_CONVERSIONUTILS_H

#pragma once
#include "cinder/Vector.h"
#include "Box2D/Box2D.h"

using namespace ci;

struct Conversions {
  static float getScaling() {
    static float scaling = 50.0f; return scaling;
  }

  static vec2 toScreen( b2Vec2 fin )
  {
    return vec2(fin.x, fin.y) * getScaling();
  }

  static b2Vec2 toPhysics( b2Vec2 fin )
  {
    return b2Vec2( fin.x/getScaling(), fin.y/getScaling() );
  }

  static float toPhysics( float fin )
  {
    return fin / getScaling();
  }

  static float toScreen( float fin )
  {
    return fin * getScaling();
  }

  static float radiansToDegrees( float rad )
  {
    return rad * 180.0f/M_PI;
  }


  static float dimensionsToPhysics(float dimension) {
    return dimension / (getScaling() * 2); //divide by 2 since Box2D shapes only store half lengths
  }

  static float dimensionsToScreen(float dimension) {
    return dimension * getScaling() * 2; //divide by 2 since Box2D shapes only store half lengths
  }
};

#endif  // FINALPROJECT_CONVERSIONUTILS_H
