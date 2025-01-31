# C++ Module 00
## Introduction
Welcome to **C++ Module 09**! This module focuses on **Standard Template Library (STL)**, leveraging STL containers and algorithms for efficient data processing. Through these exercises, you will gain hands-on experience using STL containers such as vectors, lists, maps, and implementing sorting and mathematical operations.

## General Rules
- Compilation flags: `-Wall -Wextra -Werror`.
- Use of **STL containers** (vector, list, map, etc.) and **STL algorithms** (from `<algorithm>`) is **mandatory**.
- Memory leaks must be avoided when using `new`.
- Header files should be self-contained and include necessary dependencies.
- No using `namespace <ns_name>` or `friend` keyword.

## Installation
To set up and run the project, follow these steps:
1. Clone the repository:
```
git clone https://github.com/ejarvinen/42CPP_Modules.git
cd CPP09
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./btc inputdata.txt
```
## Exercises
### Exercise 00: Bitcoin Exchange
**Objective**: Implement a program that reads a CSV file containing Bitcoin price data and evaluates the value of Bitcoin on specified dates.

### Exercise 01: Reverse Polish Notation
**Objective**: Implement a program that evaluates mathematical expressions using [Reverse Polish Notation (RPN)](https://en.wikipedia.org/wiki/Reverse_Polish_notation). The program must correctly handle `+ - * /` operations and return an error for invalid expressions.

### Exercise 02: PmergeMe
**Objective**: Implement a sorting algorithm using merge-insert sort ([Ford-Johnson algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort)) to efficiently sort large sequences of numbers. This exercise requires using **two different STL containers**.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.