//
// Created by School on 5/6/20.
//

#ifndef FINALPROJECT_CONTACTLISTENER_H
#define FINALPROJECT_CONTACTLISTENER_H

#include <Box2D/Dynamics/b2WorldCallbacks.h>

//struct Contact {
//  b2Fixture *fixtureA;
//  b2Fixture *fixtureB;
//  bool operator==(const Contact& other) const {
//    return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
//  }
//};

class ContactListener : public b2ContactListener {
 public:
//  Contact mostRecentContact;
  ContactListener();

 private:
  void BeginContact(b2Contact* contact);
  void EndContact(b2Contact contact);


};

#endif  // FINALPROJECT_CONTACTLISTENER_H
