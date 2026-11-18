# SDL3 Broken TV (TV Static Simulator)

A simple C project using **SDL3** that simulates the static noise of an old, broken television. The program creates a window and fills it with random colored pixels (white noise) at a high refresh rate.

## 📺 About the Project

This project was created to practice low-level pixel manipulation using the SDL3 software rendering API (SDL_Surface). 

The code does the following:
- Creates an 800x600 window.
- Gets the window's `SDL_Surface`.
- Locks the surface to safely write raw pixel data.
- Uses a random number generator (`rand()`) to fill every pixel with a random color.
- Properly handles the surface's `pitch` (the memory alignment of pixels per row) to prevent memory crashes.
- Unlocks the surface and updates the window to show the "static" effect.

## 🛠️ Prerequisites (What you need to run this)

To compile and run this project, you need **SDL3** installed on your system. 

**What is SDL3?**
SDL (Simple DirectMedia Layer) is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware. SDL3 is the newest major version of this library. It is not an executable program, but rather a **development library** (composed of header files `.h` and library files `.a`/`.lib`/`.dll`) that your C code needs in order to communicate with your computer's hardware.

**How to set it up:**
1. **Download the SDL3 Development Libraries:**
   Go to the [official SDL GitHub releases page](https://github.com/libsdl-org/SDL/releases) and download the MinGW development package (e.g., `SDL3-devel-x.x.x-mingw.zip`).
2. **Configure Code::Blocks (or your IDE):**
   - Extract the downloaded SDL3 folder.
   - In your IDE, add the `include` folder to your **Compiler Search Directories**.
   - Add the `lib` folder to your **Linker Search Directories**.
   - Add `-lSDL3` to your **Linker Options**.
3. **The DLL File:**
   The required `SDL3.dll` file is already included in the root of this repository. Make sure it stays in the same folder as your compiled `.exe` file, otherwise the program will crash on startup with a "missing DLL" error.

## 🚀 How to Compile and Run

If you are using **Code::Blocks**, simply open the `MyBrokenTV.cbp` project file and press **F9** (Build and Run).

If you are compiling via **command line (GCC/MinGW)**, run:
```bash
gcc main.c -o MyBrokenTV.exe -I"path/to/SDL3/include" -L"path/to/SDL3/lib" -lSDL3
