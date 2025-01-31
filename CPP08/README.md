# C++ Module 08
## Introduction
Welcome to **C++ Module 08**! This module focuses on **templated containers, iterators, and algorithms**, leveraging the Standard Template Library (STL). Through these exercises, I have gained a deeper understanding of working with templated data structures and algorithms efficiently.

## General Rules
- Compilation flags: `-Wall -Wextra -Werror`.
- STL containers (vector, list, map, etc.) and algorithms (from `<algorithm>`) are allowed and encouraged.
- Memory leaks must be avoided when using `new`.
- Header files should be self-contained and include necessary dependencies.
- No using `namespace <ns_name>` or `friend` keyword.

## Installation
To set up and run the project, follow these steps:
1. Clone the repository:
```
git clone https://github.com/ejarvinen/42CPP_Modules.git
cd CPP08
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./easyfind
```
## Exercises
### Exercise 00: Easy find
**Objective**: Implement a function template `easyfind` that searches for an integer inside a container and returns its occurrence or an error if not found.

### Exercise 01: Span
**Objective**: Implement a `Span` class that stores a collection of integers and provides methods to find the shortest and longest span between them. Optimize by utilizing iterators.

### Exercise 02: Mutated abomination
**Objective**: Implement a `MutantStack` class that extends `std::stack` and provides iterators to allow traversal.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.