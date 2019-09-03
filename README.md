# List everything sensically under each heading.  Alphabetical or something

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
    controller.cpp |  Lines: 6-10, 13-42
    game.cpp       |  Lines: 13-55, 58-71, 73-90 
    main.cpp       |  Lines: 6-22
    renderer.cpp   |  Lines: 53-88, 90-93
    snake.cpp      |  Lines: 5-22, 27-51, 63-81, 83, 92-102 

2. This project reads data from a file and processes the data, or the program writes data to a      file.  (call an outside image for a background)
    ---------- NOT AT THIS TIME ---------- if i add this it's going to change all my line numbers

3. This project accepts user input and processes the input.
    controller.cpp |  Lines: 6-10, 13-42
    game.cpp       |  Lines: 28 (calling controller.cpp) 

##      Object Oriented Programming
4. This project uses Object Oriented Programming techniques.
    controller.h   |  Lines: 6-13 (class definition)
    controller.cpp |  Lines: 6-10, 13-42 (class methods)
    game.h         |  Lines:
    game.cpp       |  Lines:
    main.cpp       |  Lines:
    rederer.cpp    |  Lines:
    renderer.h     |  Lines:
    snake.cpp      |  Lines:
    snake.h        |  Lines:    

5. Classes use appropriate access specifiers for class members.

6. Class constructors utilize member initialization lists.
    snake.h - Line # 11 (List underneath after the colon ?)

7. Classes abstract implementation details from their interfaces.

8. Classes encapsulate behavior.

9. Classes follow an appropriate inheritance hierarchy.

10. Overloaded functions allow the same function to operate on different parameters.

11. Derived class functions override virtual base class functions.

12. Templates generalize functions in the project.

##      Memory Management
13. This project makes use of references in function declarations.

14. This project uses destructors appropriately.

15. This project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

16. This project follows the Rule of 5.

17. This project uses move semantics to move data, instead of copying it, where possible.

18. This project uses smart pointers instead of raw pointers.

##      Concurrency
19. This project uses multithreading.

20. A promise and future is used in this project.

21. A mutex or lock is used in this project.

22. A condition variable is used in this project.


