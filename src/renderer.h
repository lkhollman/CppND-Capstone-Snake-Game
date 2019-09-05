#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);  //constructor
  ~Renderer(); //destructor

  void Render(Snake const snake, SDL_Point const &food); 
  void UpdateWindowTitle(int score, int fps);  //put score and frames per second in window
                                              //title.  fps in title window is good for
                                             //debugging slow game play
 private:
  SDL_Window *sdl_window;      //pointer to sdl_window object
  SDL_Renderer *sdl_renderer; //and sdl_renderer object
  
  //constant declarations
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif