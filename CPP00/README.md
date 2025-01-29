# C++ Module 00
## Introduction
Welcome to **C++ Module 00**! This repository contains exercises designed to an introduction to Object-Oriented Programming (OOP) in C++. These exercises gradually increase in complexity and help build a strong foundation in C++ development.

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
cd CPP00
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./megaphone "Hello, World!"
```
## Exercises
### Exercise 00: Megaphone
**Objective**: Write a program that transforms input text to uppercase. If no input is provided, it prints a loud noise message.

**Example Usage**:
```
$> ./megaphone "hello there"
HELLO THERE
```
### Exercise 01: My Awesome PhoneBook
**Objective**: Implement a simple phonebook that allows users to:
- Add contacts (max 8, replacing the oldest when full).
- Search contacts and display details.
- Exit the program.

**Commands**:
- `ADD`: Input contact details.
- `SEARCH`: Display a list of contacts and view details.
- `EXIT`: Quit the application.

**Example Usage**:
```
$> ./phonebook
```
## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.