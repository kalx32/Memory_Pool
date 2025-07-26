# Project Build Instructions

To compile this project, make sure you have the following tools installed and available in your `PATH`:

- `cmake` version ≥ **3.28**
- `gcc`
- `make`

### 🛠️ Build Steps

1. Open a terminal and navigate to the root directory of this project.

2. Run CMake with the `release` preset:

   ```bash
   cmake . --preset release
3. Browse to the folder containing build files
   `/cmake_build/release`
   `cd cmake_build/release`

4. Run the following command
   `make`

5. The output is built in the folder
   `/binary`
