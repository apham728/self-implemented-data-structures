# C++ Data Structures Library

A custom implementation of fundamental data structures in C++, built from scratch to deepen understanding of memory management, algorithms, and performance.

## Requirements

- CMake 3.14 or newer
- A C++20-compatible compiler
- GoogleTest

## Features

* Written in modern C++
* No use of STL containers (for learning purposes)
* Focus on efficiency and clean design
* Includes common data structures used in interviews and systems programming

## Implemented Data Structures

* ArrayList
* LinkedList (singly linked list)

## In Progress

* Stack (array and linked list style)

## Planned

* Queue (array and linked list style)
* HashMap (chained or open addressing)
* Binary Search Tree

## Example Usage

```bash
cmake --preset default
cmake --build build
./build/benchmarks data/word.txt
```

## Project Structure

```
/data       # Input file for benchmarks
/docs       # Time complexity notes
/include    # Header files
/src        # Implementation files and benchmark file
/tests      # GoogleTest unit tests
```

## What I Learned

* Dynamic memory allocation with `new` and `delete`
* Pointer usage
* Time complexity analysis
* Designing reusable classes
* Writing GoogleTest unit tests
* Benchmarking performance of data structure operations 

## Future Improvements

* Improve error handling
* Add more data structures
* Add benchmark result tables
* Compare custom implementation against STL containers
