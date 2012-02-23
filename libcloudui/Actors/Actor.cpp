#include "Actor.h"

Actor::Actor () {
}

Actor::~Actor () {
  std::vector<Actor*>::iterator it;

  for (it = children.begin (); it != children.end (); ++it) {
    delete *it;
  }
}

void
Actor::draw () const {
  std::vector<Actor*>::const_iterator it;

  for (it = children.begin (); it != children.end (); ++it) {
    (*it)->draw ();
  }
}