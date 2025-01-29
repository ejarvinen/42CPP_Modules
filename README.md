# 42CPP_Modules
## Overview
This repository contains solutions for the **42 School Curriculum C++ Modules**, a structured learning path designed to introduce and develop proficiency in **Object-Oriented Programming (OOP)** with C++. Each module focuses on a specific aspect of the language, gradually increasing in complexity and introducing key programming paradigms such as memory management, polymorphism, and the Standard Template Library (STL).

## Table of Contents
1. **Module 00** - Basics: Namespaces, Classes, Member Functions, Static, Const
2. **Module 01** - Memory Allocation, Pointers, References, Switch Statements
3. **Module 02** - Ad-hoc Polymorphism, Operator Overloading, Canonical Form
4. **Module 03** - Inheritance
5. **Module 04** - Subtype Polymorphism, Abstract Classes, Interfaces
6. **Module 05** - Exceptions and Repetition
7. **Module 06** - Type Conversions and Casting
8. **Module 07** - C++ Templates
9. **Module 08** - STL, Iterators, and Algorithms
10. **Module 09** - Advanced STL Operations

## General Guidelines
- **C++ Standard**: All projects comply with C++11 or higher.
- **Compilation**:
  - Uses `c++` with `-Wall -Wextra -Werror` flags.
- **Code Structure**:
  - Class names follow `UpperCamelCase` convention.
  - Header files (`.hpp`) include necessary dependencies and include guards.
- **Memory Management**:
  - Properly allocates and frees heap memory.
  - Prevents memory leaks.
- **Error Handling**:
  - Implements exceptions where necessary.
  - Ensure robust input validation.

## Installation and Compilation
Clone the repository and navigate to the desired module:
```
git clone https://github.com/ejarvinen/42CPP_Modules.git
cd 42CPP_Modules/CPPXX/ex0X
make
```
Execute the compiled program:
```
./program-name
```
## Modules Overview
### Module 00 - Basics
- Introduction to C++ syntax and fundamental concepts.
- Implementing classes, member functions, and simple I/O operations.

### Module 01 - Memory Management
- Dynamic memory allocation and deallocation.
- Understanding pointers and references.

### Module 02 - Operator Overloading & Polymorphism
- Overloading operators.
- Implementing the Orthodox Canonical Class Form.

### Module 03 - Inheritance
- Implementing and extending base classes.
- Exploring derived class behaviors.

### Module 04 - Abstract Classes and Interfaces
- Understanding pure virtual functions.
- Implementing abstract base classes.

### Module 05 - Exceptions
- Handling errors using exception classes.
- Implementing `try`, `catch`, and `throw`.

### Module 06 - Type Conversions
- Implementing explicit and implicit type casting.
- Understanding `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`.

### Module 07 - Templates
- Implementing function and class templates.
- Utilizing generic programming for flexibility.

### Module 08 - STL Containers & Iterators
- Introduction to STL containers (`vector`, `list`, `map`).
- Implementing iterators and algorithmic functions.

### Module 09 - Advanced STL Usage
- More complex STL operations.
- Optimizing container performance and efficiency.
