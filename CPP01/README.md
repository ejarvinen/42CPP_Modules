# C++ Module 01
## Introduction
Welcome to **C++ Module 01**! This repository contains exercises designed to enhance understanding of memory allocation, pointers to members, references, and the switch statement in C++.

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
cd CPP01
```
2. Navigate to an exercise directory (e.g., `ex00`/).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./brainz
```
## Exercises
### Exercise 00: BraiiiiiiinnnzzzZ
**Objective**: Implement a Zombie class that announces itself and must be properly allocated and deallocated.

### Exercise 01: Moar brainz!
**Objective**: Create a horde of Zombie objects dynamically and ensure proper memory management.

### Exercise 02: HI THIS IS BRAIN
**Objective**: Work with pointers and references to understand their differences and memory allocation.

### Exercise 03: Unnecessary violence
**Objective**: Implement Weapon, HumanA, and HumanB classes to simulate weapon handling differences.

### Exercise 04: Sed is for losers
**Objective**: Create a program that replaces a specific string in a file without using `std::string::replace`.

### Exercise 05: Harl 2.0
**Objective**: Implement a Harl class that prints complaints based on different severity levels using function pointers.

### Exercise 06: Harl filter
**Objective**: Implement filtering for Harl's complaints using the switch statement.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.