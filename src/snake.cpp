#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {  
  SDL_Point prev_cell{
      static_cast<int>(head_x),  //x and y coordinates and static_cast to int
      static_cast<int>(         //and store in SDL_Point prev_cell
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.
                                 //so the cell of the head is stored before update and 
                                //after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) { //are the current and
    UpdateBody(current_cell, prev_cell);                               //previous x&y the same?
  }   //if either of these are NOT the same, then the body is updated.
}

//switch with 4 cases
//in SDL the origin is the upper left corner (0,0) on Cartesian plane
//updates the float x,y position of the head
void Snake::UpdateHead() {
  switch (direction) {  //pass in direction
    case Direction::kUp:  //if direction is up
      head_y -= speed;   //the y decreases - moving toward origin
      break;

    case Direction::kDown:  //if direction is down
      head_y += speed;     //the y increases - moving away from origin
      break;

    case Direction::kLeft:  //if direction is left
      head_x -= speed;     //the x decreases
      break;

    case Direction::kRight:  //if direction is right
      head_x += speed;      //the x increases
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  //if the x coordinate is greater than the grid_width
  head_x = fmod(head_x + grid_width, grid_width);  //head_x is added in case its negative
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}