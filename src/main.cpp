#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};  //game play frames per second
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};  //compute 1000ms per second divided by frames per second
  constexpr std::size_t kScreenWidth{640};  //width in pixels
  constexpr std::size_t kScreenHeight{640};   //height in pixels
  constexpr std::size_t kGridWidth{32};   //grid of 32 cells wide
  constexpr std::size_t kGridHeight{32};   //by 32 cells high

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);  //create renderer object
  Controller controller; //create controller object
  Game game(kGridWidth, kGridHeight);  //create game object
  game.Run(controller, renderer, kMsPerFrame);  //call game.Run to start game loop; and pass in controller, renderer, and Ms/frame
  std::cout << "Game has terminated successfully!\n";  //print when game is done
  std::cout << "Score: " << game.GetScore() << "\n";   //print when game is done
  std::cout << "Size: " << game.GetSize() << "\n";    //print when game is done
  return 0;
}