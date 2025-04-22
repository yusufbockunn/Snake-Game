# 🐍 Snake Game with Reinforcement Learning (C++ & Raylib)

This is a classic **Snake Game** implemented in **C++ using Raylib**, now enhanced with a **Q-Learning Agent** based on **Reinforcement Learning** principles. The game allows the snake to learn how to survive and score points through experience.

---

## 🧠 Reinforcement Learning Integration

- The snake is controlled by a **Q-Learning Agent** that learns from **reward signals**.
- The **agent** chooses actions based on an **epsilon-greedy policy** (exploration vs. exploitation).
- The **Q-table** is updated during gameplay using the **Bellman equation**.
- Over time, the snake learns how to **maximize its score** while avoiding collisions.

### 🔢 Q-Learning Key Concepts

- **State**: The current environment the snake is in (e.g. its position, direction, food location).
- **Action**: Move `Up`, `Down`, `Left`, or `Right`.
- **Reward**: Positive for eating food, negative for hitting walls or itself.
- **Update Rule**:






---

## 🎮 Gameplay

- Control the snake using **arrow keys** or switch to **AI mode** to let the Q-agent take over.
- Eat the food to grow and increase your score.
- The snake **wraps around the screen** if it hits the wall.
- The game ends if the snake **collides with itself**.

---

## 📷 Screenshots

<p align="center">
<img src="https://github.com/user-attachments/assets/b3f1f9ca-b0cf-4477-abc5-b065a5f4163d" width="45%" />
<img src="https://github.com/user-attachments/assets/43488e8e-2537-4c05-a150-475caf7368bb" width="45%" />
</p>

---

## 🔧 Installation & Running

### 1️⃣ Requirements

To build and run this project, you need:

- A modern **C++ compiler** (GCC, MSVC, or Clang)
- **Raylib** library installed
- **CMake** (optional)
- **Windows, Linux, or macOS**
- A text editor or an IDE (VS Code, CLion, etc.)

### 2️⃣ Installing Raylib

#### 🪟 Windows (MSYS2 + MinGW-w64)

1. Install **MSYS2** from [msys2.org](https://www.msys2.org/)
2. Open **MSYS2 terminal** and run:
 ```sh
 pacman -S mingw-w64-x86_64-raylib
