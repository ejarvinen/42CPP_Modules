# C++ Module 06
## Introduction
Welcome to **C++ Module 06!** This module covers **C++ casts**, focusing on different types of type conversions and their appropriate use cases. These exercises have deepened my understanding of safe type conversion in C++ and serialization techniques.

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
cd CPP06
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./convert 42
```
## Exercises
### Exercise 00: Conversion of scalar types
**Objective**: Implement a `ScalarConverter` class that converts a string representation of a scalar type (`char`, `int`, `float`, `double`) and outputs its converted values.

### Exercise 01: Serialization
**Objective**: Implement a `Serializer` class to convert a pointer to an unsigned integer (`uintptr_t`) and back, ensuring serialization works correctly.

### Exercise 02: Identify real type
**Objective**: Implement a `Base` class with derived classes `A`, `B`, and `C`. Write functions to identify the actual type of an object dynamically without using `std::typeinfo`.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.