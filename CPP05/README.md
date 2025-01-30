# C++ Module 05
## Introduction
Welcome to **C++ Module 05**! This module covers **repetition and exceptions**, focusing on handling errors and designing robust, hierarchical class structures in C++. These exercises have strengthened my understanding of exception handling and class organization.

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
cd CPP05
```
2. Navigate to an exercise directory (e.g., `ex00/`).
3. Compile using the provided Makefile:
```
make
```
4. Run the program:
```
./bureaucrat
```
## Exercises
### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
**Objective**: Implement a `Bureaucrat` class with a constant name and a grade ranging from 1 to 150. Include exception handling for invalid grade assignments.

### Exercise 01: Form up, maggots!
**Objective**: Introduce a `Form` class with attributes for signing status and required grades. Implement logic to allow bureaucrats to sign forms if their grade permits.

### Exercise 02: No, you need form 28B, not 28C...
**Objective**: Convert `Form` into an abstract class (`AForm`). Implement specific form types (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) with distinct behaviors upon execution.

### Exercise 03: At least this beats coffee-making
**Objective**: Implement an `Intern` class capable of creating different form types dynamically using a `makeForm()` method, avoiding cumbersome if-else logic.

## Compilation & Formatting
- Code should follow the C++11 standard or later and be formatted for readability.
- Forbidden functions: `printf()`, `malloc()`, `free()`.
- Class names must follow `UpperCamelCase` naming convention.