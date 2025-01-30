# C++ Module 07
## Introduction
Welcome to **C++ Module 07**! This module covers **C++ templates**, focusing on creating reusable and generic code structures. These exercises have deepened my understanding of template functions and template classes.

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
cd CPP07
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./whatever
```
## Exercises
### Exercise 00: Start with a few functions
**Objective**: Implement function templates for `swap`, `min`, and `max` that operate on generic types.

### Exercise 01: Iter
**Objective**: Implement a function template `iter` that applies a given function to each element of an array.

### Exercise 02: Array
**Objective**: Implement a class template `Array<T>` that mimics the behavior of a dynamically allocated array, supporting deep copies and bound checking.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.