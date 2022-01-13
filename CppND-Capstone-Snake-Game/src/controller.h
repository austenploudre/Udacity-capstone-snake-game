#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  //initialize pause state
  Controller(): _pause(false){}
  void HandleInput(bool &running, Snake &snake);
  void ChangePauseState();
  bool GetPauseState() const;

 private:
  bool _pause;  // manage pause state
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
