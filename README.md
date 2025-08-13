# Sorting Algorithm Visualizer (C++)

A terminal-based **sorting visualizer** built in C++ that demonstrates sorting algorithms using **real-time colored animations** in the console.  
The program generates a random array of 50–500 elements and visually sorts them step-by-step using **Selection Sort**.

## Features
- 🎨 **Color-coded columns** using ANSI escape codes for better visibility:
  - Cyan → Unsorted elements
  - Magenta → Elements being compared
  - Green → Sorted portion
- 📊 **Adaptive column width** to fit terminal screen for up to 500 elements.
- 🔢 Displays the **numeric values** directly under each column.
- ⚡ Real-time animation with smooth iteration steps.
- 🖥 Works in any modern terminal that supports ANSI colors (Linux, macOS, Windows with ANSI enabled).

## How It Works
1. **Generates a random array** of length between 50 and 500.
2. **Assigns random heights** (1–40) to each element.
3. Uses **Selection Sort** to sort the array:
   - Highlights compared elements in magenta.
   - Marks sorted portion in green.
   - Updates display after each iteration.

## Example Output
