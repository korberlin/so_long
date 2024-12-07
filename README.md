```markdown
# so_long

![so_long Cover](imgs/cover-so_long-bonus.png)

Welcome to my **so_long** project! 🌍🦈 This is a basic 2D game developed using **MiniLibX**, where you guide a character through a map, collect all the items, and find the exit.  
![so_long Passed with Bonus](imgs/so_longm.png)

---

## About
**so_long** is a project from 42 Berlin designed to enhance your skills in:
- Window management & event handling with the **MiniLibX**.
- File parsing and validating map configurations.
- Pathfinding logic, using a **flood fill algorithm** to ensure the map is playable.
- Working with basic 2D graphics, sprite animation, and score displays.

Through this project, I learned:
- How to integrate and manage graphical elements in a C project.
- Techniques for validating maps (checking their shape, ensuring they are fully walled in, and that characters are correctly placed).
- Handling user input (W, A, S, D) for character movement.
- Implementing sprite animations for a richer visual experience.
- Displaying the current score directly on the screen for a more engaging gameplay experience.

This project has been tested on Linux machines.

---

## Features
- **Map Components:**
  - **0:** Empty space
  - **1:** Wall
  - **C:** Collectible
  - **E:** Exit
  - **P:** Player start position
  
- **Gameplay:**
  - Collect all **C** items.
  - Reach the **E** (exit) after collecting all items.
  - Move using **W, A, S, D**.
  - Walls (1) are impassable, ensuring you must navigate valid paths.
  
- **Path Validation:**
  - The map must be rectangular and surrounded by walls.
  - The flood fill algorithm ensures there is a valid path that allows collecting all collectibles and reaching the exit.
  
- **Bonus Highlights:**
  - **Sprite Animation:** Characters and possibly other elements come to life through simple animations.
  - **Score Display:** Your score or movement count appears directly on the screen, enhancing the gameplay experience.

- **Controls:**
  - **W, A, S, D:** Move Up, Left, Down, Right.
  - **ESC or Window Close:** Quit the game.

---

## How to Run
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/korberlin/so_long.git
   cd so_long
   ```

2. **Compile the Project:**
   ```bash
   make
   ```
   This will generate the `so_long` executable.

3. **Run the Game:**
   ```bash
   ./so_long maps/example.ber
   ```
   Replace `example.ber` with the path to your own `.ber` map file.

---

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve the code, add new features, or enhance the gameplay experience.

---

**Thank you for exploring my so_long project!** Enjoy the game and have fun! 🎉
```
