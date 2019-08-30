#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight }; 

  Snake(int grid_width, int grid_height)  //Snake constructor
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),        //sets the initial position
        head_y(grid_height / 2) {}    //for the snake head.  x & y coordinates.
                                     //starts snake in the middle of the screen.

  void Update();  //method for updating the snake on each pass of the game loop

  void GrowBody();  //method to grow the body of the snake each time it eats food
  bool SnakeCell(int x, int y);  //boolean to determine if an x,y coordinate is part of the snake

  Direction direction = Direction::kUp; //initially set the direction of the snake to Up

  float speed{0.1f};  //speed of snake
  int size{1};   //size of snake
  bool alive{true};   //is snake alive
  float head_x;  //x,y position of the head of the snake
  float head_y;
  std::vector<SDL_Point> body;  //vector of SDL points for the body of the snake. 
                               //SDL_Point is a struct int x&y coordinates

 private:
  void UpdateHead();  //when Update is called it will UpdateHead
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);  //and UpdateBody with the new
                                                                  //coordinates of the body.
  bool growing{false};  //decide of the snake is growing and then on the next game loop
                       //the body is set to the new length.
  int grid_width;   //the game play grid width
  int grid_height; //and height
};

#endif