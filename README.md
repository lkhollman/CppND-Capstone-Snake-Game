# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

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
1. DELETE build directory from project
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
    ------------------------------------------------------------
    * controller.cpp |  Lines: 6-10, 13-42
    * game.cpp       |  Lines: 13-55, 58-71, 73-90 
    * main.cpp       |  Lines: 6-22
    * renderer.cpp   |  Lines: 53-88, 90-93
    * snake.cpp      |  Lines: 5-22, 27-51, 63-81, 83, 92-102 
    ------------------------------------------------------------
    
2. This project accepts user input and processes the input.
    * controller.cpp |  Lines: 6-10, 13-42
    * game.cpp       |  Lines: 28 (calling controller.cpp) 

##      Object Oriented Programming
3. This project uses Object Oriented Programming techniques.
    * controller.h   |  Lines: 6-13 (class definition)
    * controller.cpp |  Lines: 6-10, 13-42 (class methods)
    * game.h         |  Lines: 10-33 (class definition)
    * game.cpp       |  Lines: 5-11, 13-55, 58-71, 73-90, 93, 94 
                      		(class methods)
    * main.cpp       |  Lines: 14, 15, 16, 17, 19, 20
                      		(object calls) 
    * rederer.cpp    |  Lines: 5-11, 53-88, 90-93
                      		(class methods)
    * renderer.h     |  Lines: 8-27 (class definition)
    * snake.cpp      |  Lines: 5-22, 27-51, 63-81, 83, 92-102
                      		(class methods)
    * snake.h        |  Lines: 7-41 (class definition)

4. Classes use appropriate access specifiers for class members.
    * controller.h   |  Lines: (Public) 8, (Private) 11
    * game.h         |  Lines: (Public) 12-16, (Private) 19-32
    * renderer.h     |  Lines: (Public) 10-15, (Private) 19-26
    * snake.h        |  Lines: (Public) 9-30, (Private) 34-40

5. Class constructors utilize member initialization lists.
    * game.cpp       |  Lines: 6-9
    * renderer.cpp   |  Lines: 8-11
    * snake.h        |  Lines: 12-15

6. Classes encapsulate behavior.
    * Uses classes controller.h, game.h, renderer.h, and snake.h in order to encapsulate behavior.