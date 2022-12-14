//
// Created by School on 5/6/20.
//

#include "mylibrary/ContactListener.h"

#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include <mylibrary/PlayerBody.h>

void ContactListener::BeginContact(b2Contact* contact) {
  void* fixtureUserData = contact->GetFixtureA()->GetUserData();
  std::cout << "Begin contact" << std::endl;
  if (fixtureUserData) {
    PlayerBody* temp = static_cast<PlayerBody*>(fixtureUserData);
   if (dynamic_cast<PlayerBody*>(temp) != nullptr) {
     std::cout << "touchedGround A" << std::endl;

      static_cast<PlayerBody*>(fixtureUserData)->touchedGround();
    }
  }
//
  fixtureUserData = contact->GetFixtureB()->GetUserData();

  if (fixtureUserData) {
    PlayerBody* temp = static_cast<PlayerBody*>(fixtureUserData);
    if (dynamic_cast<PlayerBody*>(temp) != nullptr) {
      std::cout << "touchedGround B" << std::endl;

      static_cast<PlayerBody*>(fixtureUserData)->touchedGround();
    }
  }

}
ContactListener::ContactListener() {}
