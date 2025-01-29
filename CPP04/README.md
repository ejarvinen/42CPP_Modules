# C++ Module 04
## Introduction
Welcome to **C++ Module 04**! This repository contains exercises designed to introduce subtype polymorphism, abstract classes, and interfaces in C++. These exercises have helped gain a deeper understanding of Object-Oriented Programming (OOP) principles.

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
cd CPP04
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./animal
```
## Exercises
### Exercise 00: Polymorphism
**Objective**: Implement an `Animal` base class and derive `Dog` and `Cat` classes. Ensure proper function overriding for `makeSound()` and test the behavior of polymorphism.

### Exercise 01: I don’t want to set the world on fire
**Objective**: Implement a `Brain` class and add it as a private member to `Dog` and `Cat`. Ensure deep copying is performed correctly.

### Exercise 02: Abstract class
**Objective**: Modify the `Animal` class to be abstract, preventing direct instantiation while maintaining its functionality in derived classes.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.