# C++ Module 03
## Introduction
Welcome to **C++ Module 03**! This repository contains exercises designed to introduce the concept of Inheritance in C++. These exercises will explore how to build a hierarchy of classes and understand the importance of proper class design.

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
cd CPP03
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./claptrap
```
## Exercises
### Exercise 00: Aaaaand... OPEN!
**Objective**: Implement a ClapTrap class with attributes for hit points, energy points, and attack damage. Include member functions for attacking, taking damage, and repairing itself.

### Exercise 01: Serena, my love!
**Objective**: Create a `ScavTrap` class that inherits from `ClapTrap`. It should have modified attributes and an additional member function `guardGate()`.

### Exercise 02: Repetitive work
**Objective**: Implement a `FragTrap` class that inherits from `ClapTrap`. Modify its attributes and add a special function `highFivesGuys()`.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.