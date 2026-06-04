# Snake

A classic Snake game built in C++17 with [raylib](https://www.raylib.com/).

The snake moves across a 1800×1040 grid (20 px cells). Eat food to grow; hitting a wall or yourself ends the game. Press Enter to restart after a game over.

## Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `Enter` | Start / restart |

## Project structure

```
.
├── main.cpp          # Entry point, game loop, input
├── Game.h / .cpp     # Orchestrates snake, food, collision, game-over
├── Snake.h / .cpp    # Snake body, movement, self-collision
├── Food.h / .cpp     # Food placement, random respawn
├── Includes.h / .cpp # Shared constants (colors, screen size, cell size)
├── include/          # raylib.h, raymath.h, rlgl.h
├── lib/              # libraylib.a (pre-compiled static library)
└── Graphics/         # Game assets (food.png)
```

## Building

### Prerequisites

- CMake 3.20+
- A C++17 compiler (Clang, GCC, or MSVC)
- raylib (system install **or** the bundled `lib/libraylib.a`)

**macOS (Homebrew)**
```bash
brew install raylib
```

**Ubuntu / Debian**
```bash
sudo apt install libraylib-dev
```

**Windows (vcpkg)**
```bash
vcpkg install raylib
```

If you skip the system install, the build falls back automatically to the pre-compiled `lib/libraylib.a` that ships with the repo.

### Build steps

```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

The executable is placed in `build/bin/Snake` (or `build/bin/Snake.exe` on Windows). The `Graphics/` folder is copied next to it automatically.

### Run

```bash
./build/bin/Snake
```
