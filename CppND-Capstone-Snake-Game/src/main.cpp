#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <chrono>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.SetPlayerName();
  //game.UpdateDifficulty();
  //start game clock
  auto start = std::chrono::system_clock::now();  
  game.Run(controller, renderer, kMsPerFrame);
  //game.SetPlayerGameTime();
  //end game clock
  auto end = std::chrono::system_clock::now();
  //calculate time elapsed
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Name: " << game.GetPlayerName() << "\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  std::cout << "Elapsed Time: " << duration.count() << " seconds" << "\n";
  return 0;
}
