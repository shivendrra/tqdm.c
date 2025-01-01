# TQDM Library

A lightweight and customizable progress bar library for C/C++ applications, designed to provide a feature-rich yet simple API for tracking and visualizing progress in terminal-based applications.


## Features

- Displays a progress bar with percentage, elapsed time, remaining time, and processing rate.
- Supports scaling units for rate display (e.g., items/s, k-items/s).
- Fully customizable for integration into various projects.
- Includes helper functions for pretty-printing and traversal of custom structures.
- Compatible with both C and C++ projects.


## Getting Started

### Prerequisites

- A C/C++ compiler supporting C99 or later.

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/shivendrra/tqdm.c.git
   cd tqdm.c
   ```

2. Include the `tqdm.h` file in your project.


## Usage

### Basic Example (C)

```c
#include "tqdm.h"
#include <unistd.h> // For usleep

int main() {
  tqdm bar;
  init_tqdm(&bar, "Loading", false, "items", true, 100, 10);

  for (int i = 0; i <= 100; ++i) {
    update_tqdm(&bar, 1, false);
    usleep(50000); // Simulate work
  }

  close_tqdm(&bar);
  return 0;
}
```

### Basic Example (C++)

```cpp
#include "tqdm.h"
#include <thread>
#include <chrono>

int main() {
  tqdm bar;
  init_tqdm(&bar, "Processing", false, "tasks", true, 50, 5);

  for (int i = 0; i <= 50; ++i) {
    update_tqdm(&bar, 1, false);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
  }

  close_tqdm(&bar);
  return 0;
}
```

## API Reference

### Functions

#### `void init_tqdm()`
Initializes a progress bar structure.

#### `void update_tqdm()`
Updates the progress bar with the specified increment.

#### `void print_tqdm()`
Displays the progress bar on the terminal.

#### `void close_tqdm()`
Finalizes and disables the progress bar.

#### `void HMS()`
Formats a duration in seconds into an HH:MM:SS string.

#### `void SI()`
Formats a numeric value into a scaled SI string (e.g., 1.2k).

#### `char* pretty_print()`
Performs recursive pretty-printing for custom structures.

#### `void dfs()`
Performs a depth-first traversal of a structure.


## Contributing

Contributions are welcome! Please follow these steps:

1. Fork this repository.
2. Create a feature branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m 'Add feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Open a pull request.



## License

This project is licensed under the MIT License. See the `LICENSE` file for details.


## Acknowledgments

Inspired by the Python `tqdm` library. Main implementation from the [TinyGrad](https://github.com/tinygrad/tinygrad/blob/master/tinygrad/helpers.py)'s TQDM implementation.