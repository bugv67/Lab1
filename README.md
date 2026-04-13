# Lab1

-----part 0 ----
make part0
run wrod1 //has segmetatiob fault
run word1 word2 // prints The sentece contains 2 words
quit // to exit the program

to debug: # Lab 1: Memory Management & Functional C

## Overview

This project explores the low-level memory architecture of C programs and demonstrates advanced techniques such as manual memory management, pointer arithmetic, and functional programming patterns using function pointers.

## How to Build and Run

To compile the project using the provided Makefile:
make clean
make

-------part0----
./part0
Hello Noa, testing Task 0!
[Press Ctrl+D] // should return the numbers of words

------part1-------
./part1
hello world 123 // should see a tons of addresses prints- learning about the memory

------part2+3------
./part3
g //geting input
noa!! // filling the array-sixe5
d //should return the decimal rep of each char
e // encoding the string- adds 1
h // should return the hexcimal rep of each char
i // decrypt back

## Key Components

### 1. Memory Layout Analysis

- **Segment Forensics:** Investigated the placement of variables in the **Stack, Heap, Data, and Text** segments.
- **Architecture Verification:** Analyzed memory distances and verified type sizes for 32-bit architecture (`-m32`).
- **Array Memory Mapping:** Visualized how different data types (`int`, `char`, `double`) are aligned and accessed in memory.

### 2. Functional Mapping System

- **Generic Map Function:** Implemented a robust `map` function that processes arrays dynamically.
- **Processing Suite:** Created a library of character manipulation tools including:
  - `my_get`: Standard input handling.
  - `dprt` / `cxprt`: Formatted output (Decimal and Hexadecimal).
  - `encrypt` / `decrypt`: Caesar-style character shifting.

### 3. Interactive Menu System

- **Object Simulation:** Used `structs` and **function pointers** to simulate object-oriented behavior.
- **Memory Safety:** Implemented a loop that handles dynamic array updates with strict `malloc` and `free` management to prevent memory leaks.
- **Robust I/O:** Built to handle EOF signals (`Ctrl+D`) for clean program termination.

## Skills & Technologies

- **Language:** C (Standard Library)
- **Memory Management:** Dynamic allocation, Pointer arithmetic, Memory safety.
- **Architecture:** 32-bit System Programming.
- **Build Tools:** Makefile automation.
- **Environment:** Linux / WSL.

```

```
