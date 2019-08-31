#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);  //calling methods to run the game.
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;  //a struct with x&y coordinates

  //random device used to find a location to place the food. 
  std::random_device dev;  //standard random device put into the dev variable.
                          //used as a seed for a random number engine.
  std::mt19937 engine;  //psuedo random number generator engine.
  std::uniform_int_distribution<int> random_w;   //standard uniform distribution to generate
  std::uniform_int_distribution<int> random_h;  //x,y coordinates to place next food.

  int score{0};

  void PlaceFood();
  void Update();
};

#endif