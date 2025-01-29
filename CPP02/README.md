# C++ Module 02
## Introduction
Welcome to **C++ Module 02**! This repository contains exercises designed to enhance understanding of ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form in C++.

## General Rules
- Compilation flags: `-Wall -Wextra -Werror`.
- No external libraries allowed.
- Memory leaks must be avoided when using `new`.
- Header files should be self-contained and include necessary dependencies.
- No using `namespace <ns_name>` or `friend` keyword.

## Installation
To set up and run the project, follow these steps:
1. Clone the repository:
```
git clone https://github.com/ejarvinen/42CPP_Modules.git
cd CPP02
```
2. Navigate to an exercise directory (e.g., `ex00`/).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./fixed
```
## Exercises
### Exercise 00: My First Class in Orthodox Canonical Form
**Objective**: Implement a `Fixed` class in the Orthodox Canonical Form that represents a fixed-point number with integer storage and 8 fractional bits.

### Exercise 01: Towards a more useful fixed-point number class
**Objective**: Extend the `Fixed` class by adding constructors for integers and floating-point numbers, conversion functions, and operator overloading.

### Exercise 02: Now we're talking
**Objective**: Overload comparison, arithmetic, and increment/decrement operators in the `Fixed` class. Implement `min` and `max` functions to compare values.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.