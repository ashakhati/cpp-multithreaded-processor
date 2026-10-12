# C++ Multithreaded Job Processor

## Overview

A multithreaded job processor implemented in modern C++20. The application uses a shared, thread-safe job queue to distribute jobs among multiple worker threads.

The project demonstrates fundamental C++ concurrency concepts, including thread creation, mutual exclusion, condition variables, and graceful shutdown.

## Features

* Multiple worker threads process jobs concurrently.
* A shared FIFO queue stores pending jobs.
* Mutexes protect shared queue state.
* Condition variables allow workers to wait efficiently for jobs.
* Graceful shutdown allows pending jobs to be processed before workers exit.
* CMake is used to configure and build the project.

## Technologies

* **Language:** C++20
* **Build system:** CMake
* **Concurrency:** `std::thread`, `std::mutex`, `std::condition_variable`
* **Standard library:** `std::queue`, `std::vector`
* **Platform:** Linux / WSL

## Project Structure

```text
cpp-multithread-processor/
├── CMakeLists.txt
├── README.md
└── src/
    ├── main.cpp
    ├── JobQueue.h
    └── JobQueue.cpp
```

## How It Works

1. The main function creates a shared `JobQueue`.
2. Three worker threads are started.
3. Ten jobs are added to the queue.
4. Workers retrieve jobs from the shared queue and print which job they are processing.
5. The queue is stopped, allowing workers to finish pending jobs.
6. The main thread waits for all workers to finish using `join()`.

The order of output may vary because multiple threads execute independently.

## Build and Run

Make sure CMake and a C++20-compatible compiler are installed.

Configure the project:

```bash
cmake -S . -B build
```

Build the application:

```bash
cmake --build build
```

Run it:

```bash
./build/concurrent_processor
```

## Key C++ Concepts Demonstrated

* Classes, encapsulation, and header/source separation
* References and `std::ref`
* STL containers and FIFO queue operations
* Thread creation and joining
* Mutexes and RAII-based locking
* Condition variables and predicate-based waiting
* Shared-state synchronization
* Graceful thread shutdown

## Learning Objectives

This project was developed to practise modern C++ concurrency, understand thread-safe resource sharing, and build a foundation for more advanced multithreaded applications.

## Current Scope

Jobs currently demonstrate queue processing through console output. Automated tests, more advanced error handling, and additional processing functionality may be added in future iterations.
