# Fraction Calculator (C++ / CLion)

A minimal yet clean implementation of a **Fraction (`Fraction`) class** in C++, featuring:

- Automatic normalization (GCD simplification, negative denominator handling, zero checks)
- Operator overloading for `+`, `-`, `*`, `/`, unary `+` and `-`, and all comparisons (`==`, `!=`, `<`, `<=`, etc.)
- Stream I/O (`operator<<`, `operator>>`) with input validation
- Two execution modes:
  - `main.cpp` → quick internal tests
  - `Fraction_CLI.cpp` → interactive command-line calculator (`3/4 + 2/5`)

> A small project to practice clean OOP design, exception handling, and C++ fundamentals.

---

## 📁 Project Structure
.
├── Fraction.h
├── Fraction.cpp
├── Fraction_CLI.cpp # interactive CLI: a/b <op> c/d
└── main.cpp # quick tests (assert-based)

---

## ✨ Features
- ✅ **Normalization:** Simplifies using `std::gcd`; ensures consistent sign handling and zero safety.
- ✅ **Exceptions:** Throws `std::invalid_argument` for invalid denominators.
- ✅ **Safe comparisons:** Prevents overflow via scaled integer logic (or `__int128` if available).
- ✅ **Stream I/O:** Accepts both `n/d` and integer `n`; restores stream state on invalid input.

---

## ⚙️ Build Instructions

### Requirements
- C++17 or later
- CMake ≥ 3.15
- GCC / Clang / MSVC
- (Optional) **CLion IDE**

### Build with CMake
```bash

This produces:

build/Fraction_CLI (interactive mode)

build/tests_basic (unit tests)

If you don’t have a CMakeLists file yet, create one:

cmake_minimum_required(VERSION 3.15)
project(FractionCalculator CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(fraction STATIC Fraction.cpp Fraction.h)

add_executable(Fraction_CLI Fraction_CLI.cpp)
target_link_libraries(Fraction_CLI PRIVATE fraction)

add_executable(tests_basic main.cpp)
target_link_libraries(tests_basic PRIVATE fraction)

-----------------------------------------------------

Quick Build without CMake (Linux / macOS) ->
g++ -std=c++17 -O2 Fraction.cpp Fraction_CLI.cpp -o Fraction_CLI
g++ -std=c++17 -O2 Fraction.cpp main.cpp -o tests_basic

Windows (PowerShell, MSVC)
cl /std:c++17 /O2 Fraction.cpp Fraction_CLI.cpp /Fe:Fraction_CLI.exe
cl /std:c++17 /O2 Fraction.cpp main.cpp /Fe:tests_basic.exe


▶️ Run Examples (PowerShell)
Interactive Mode
-------------------
./Fraction_CLI

Example session:
Enter your Expression. (e.g. 3/4 + 2/5). Type 'exit' to quit.
> 3/4 + 2/5
= 23/20
> 5 - 1/2
= 9/2
> exit
---------------------------------------------------------------------

Run one-liner expressions:
./Fraction_CLI "3/4 + 5/6"
# Output: = 19/12
---------------------------------------------------------------------

🧩 Input & Error Handling

Accepts both n/d and integer n

Examples:

"3/4" → valid

"5" → valid (treated as 5/1)

"7/" or "2/0" → invalid, stream fail state triggered

Division by zero or invalid denominator throws std::invalid_argument
----------------------------------------------------------------------
🚀 Future Improvements

 Unit tests with GoogleTest / Catch2

 Parser supporting parentheses & precedence

 Benchmarks for normalization performance

 GitHub Actions CI for cross-platform builds
----------------------------------------------------------------------
🧾 License

MIT License — feel free to use, modify, and learn from it.
----------------------------------------------------------------------
🧠 About

This project was created by Kasra,
a Computer Science (M.Sc.) student based in Berlin, passionate about software engineering, clean code, and building real skills through small, focused projects.








cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
