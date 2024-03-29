#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <string>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
 
  std::string GetPlayerName();
  int GetScore() const;
  int GetSize() const;
  void SetPlayerName();
  void UpdateDifficulty();

 private:
  Snake snake;
  SDL_Point food;
  SDL_Point poison;
  std::string player_name;
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  
  int score{0};
  void PlaceFood();
  void PlacePoison();
  void Update(const Controller &controller);

};

#endif
