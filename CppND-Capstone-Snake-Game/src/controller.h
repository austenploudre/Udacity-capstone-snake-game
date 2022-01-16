#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  // Initialize pause state
  Controller(): _pause(false){}
  void HandleInput(bool &running, Snake &snake);
  void ChangePauseState();
  bool GetPauseState() const;

 private:
  // Manage pause state
  bool _pause;  
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
