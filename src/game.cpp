#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),  //initialize snake with grid_width & grid_height.
      engine(dev()),  //initialize the random engine device.
      random_w(0, static_cast<int>(grid_width)),    //initialize the random number between 0
      random_h(0, static_cast<int>(grid_height)) { //and grid_width, and 0 and grid_height.
  PlaceFood();  //and then place food on the screen.
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;  //variable to pass to the while loop. creates an infinite loop until 
                       //game play is to stop, because the game has ended.

  while (running) {
    frame_start = SDL_GetTicks();    //a single frame of the game starts here and ends at 
                                    //frame_end

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);  //pass in running and snake.
    Update();
    renderer.Render(snake, food);  //render game with the snake and the food

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;  //increment frame count by 1 
    frame_duration = frame_end - frame_start;  //determine how long it took to make this frame.

    // After every second, update the window title.
    //it would be unnecessary and resource intensive to render every single loop.
    if (frame_end - title_timestamp >= 1000) {  //1000 Ms, or 1 second
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;  //reset the frame counter to 0.
      title_timestamp = frame_end;  //reset the timestamp to the end of the frame for the 
    }                              //next loop through
    
    //If the game is running too fast slow it down
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);  //delay as much as needed in order to
    }                                                    //have consistent game play 
  }
}


void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);  //produce random numbers for x,y coordinates to potentially place
    y = random_h(engine); //food. 
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {  //if snake isn't in cell
      food.x = x;                 //set x coordinate
      food.y = y;                //and set y coordinate
      return;
    }
  }
}

void Game::Update() {   
  if (!snake.alive) return; //check if snake is alive.  if it isn't return

  snake.Update();    //snake is alive, so update snake

  int new_x = static_cast<int>(snake.head_x);  //get the new x and
  int new_y = static_cast<int>(snake.head_y); //y for the snake head.

  // Check if there's food over here
  //check if snake head is in the same cell as the food
  if (food.x == new_x && food.y == new_y) {
    score++;  //increment score because food was found
    PlaceFood();   //place another food on the screen
    // Grow snake and increase speed.
    snake.GrowBody();  //grow snake
    snake.speed += 0.02;  //increase the snake speed to increase difficulty
  }
}

//return score and snake size for the window stats at the top.
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }