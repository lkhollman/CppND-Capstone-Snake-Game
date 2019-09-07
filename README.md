# CPPND: Capstone Snake Game
This is a clone of the traditional Snake Game.  

Once installed and loaded, simply use the arrow keys to operate the direction of the snake on the screen.  The object of the game is to guide the snake to the yellow squares (food) on the screen, so the snake will eat them.  

<img src="snake_game.gif"/>

## File and Class Structure 
The SDL2 Library is utilized for overall functionality.

### main.cpp 
Initiates program and settings for game play:  sets game play frames per second, screen size in pixels, and the establishes the grid size for the snake to navigate through.

Creates the following objects: renderer, controller, and game

Calls game.Run to start the game.

Prints final messages to the console when game is over.

### controller.cpp 
Detects which arrow key is pressed.

### game.cpp
Contains the game loop.  Takes the input from controller, produces a random x,y coordinate for food placement, and renders it to the screen through the renderer class.

Maintains frame rate by measuring how much time operations take to complete; ensuring consistent game play.

Speed of snake is increased each time a food item is eaten.

Checks if snake is alive before continuing.

Returns score and Frames Per Second (FPS), so SDL can place in title bar of game window.

### renderer.cpp
Utilizes the SDL library to create a window and constantly update the window with the location of the snake, the food item, and the title bar information; Score and Frames Per Second (FPS).

### snake.cpp
Updates the current position of the head of the snake.

Checks to make sure the snake is moving.

Handles operations for making the snake wrap around the edge of window to the other side for continuous movement.

Decides if snake has died.

Checks to see if snake is growing in size.

Checks current location of snake to help in placement of next food item.  Food can't be placed on top of the snake.

## Expected Behavior and Output
Each food item eaten increases score and the moving speed of the snake.  

The game ends when the snake runs into its own body.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
1. Delete build directory from project
2. Make a new build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
    3a. If you get the following error:
        "Target "SnakeGame" links to item "-L/usr/lib/x86_64-linux-gnu -lSDL2 which has leading or trailing whitespace.  This is now an error according to policy CMP0004."

        Type the following at the prompt:
        > sudo vim '/usr/lib/x86_64-linux-gnu/cmake/SDL2/sdl2-config.cmake'

        or navigate to your sdl2-config.cmake file and edit with the following:
        find "-ISDL2 " at the end of the file and delete the trailing space.
4. Run it: `./SnakeGame`.

## Requirements.  Specifications and Line numbers of each requirement implemented.

##      Loops, Functions, I/O
1. This project demonstrates an understanding of C++ functions and control structures.
    
    File | Lines:
    ---- | ------------
    controller.cpp | 6-10, 13-42
    game.cpp       | 13-55, 58-71, 73-90 
    main.cpp       | 6-22
    renderer.cpp   | 53-88, 90-93
    snake.cpp      | 5-22, 27-51, 63-81, 83, 92-102 
    
2. This project accepts user input and processes the input.

    File | Lines:
    ---- | ------------
    controller.cpp |  6-10, 13-42
    game.cpp       |  28 (calling controller.cpp) 

##      Object Oriented Programming
3. This project uses Object Oriented Programming techniques.

    File | Lines:
    ---- | ------------
    controller.h   |  6-13 (class definition)
    controller.cpp |  6-10, 13-42 (class methods)
    game.h         |  10-33 (class definition)
    game.cpp       |  5-11, 13-55, 58-71, 73-90, 93, 94 (class methods)
    main.cpp       |  14, 15, 16, 17, 19, 20 (object calls) 
    rederer.cpp    |  5-11, 53-88, 90-93 (class methods)
    renderer.h     |  8-27 (class definition)
    snake.cpp      |  5-22, 27-51, 63-81, 83, 92-102 (class methods)
    snake.h        |  7-41 (class definition)

4. Classes use appropriate access specifiers for class members.

    File | Lines:
    ---- | ------------
    controller.h   |  (Public) 8, (Private) 11
    game.h         |  (Public) 12-16, (Private) 19-32
    renderer.h     |  (Public) 10-15, (Private) 19-26
    snake.h        |  (Public) 9-30, (Private) 34-40

5. Class constructors utilize member initialization lists.

    File | Lines:
    ---- | ------------
    game.cpp       |  6-9
    renderer.cpp   |  8-11
    snake.h        |  12-15

6. Classes encapsulate behavior.
    * Uses the following classes to encapsulate behavior: controller.h, game.h, renderer.h, and snake.h