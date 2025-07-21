# Philosophers (philo & philo_bonus)

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [The Dining Philosophers Problem](#the-dining-philosophers-problem)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Arguments](#arguments)
- [Bonus Version](#bonus-version)
- [Notes](#notes)

---

## Overview

This project is an implementation of the classic **Dining Philosophers Problem** using C, with two versions:
- `philo`: Uses threads and mutexes.
- `philo_bonus`: Uses processes and semaphores.

The goal is to simulate philosophers sitting at a table, alternating between thinking, eating, and sleeping, while sharing forks (resources) and avoiding deadlocks and starvation.

---

## Project Structure

```
philosophers-42/
  philo/           # Main project (threads & mutexes)
    includes/
      philo.h
      structs.h
    main.c
    Makefile
    srcs/
      utile1.c
      utile2.c
      utile3.c
      utile4.c
  philo_bonus/     # Bonus project (processes & semaphores)
    includes/
      philo_bonus.h
      structs_bonus.h
    main.c
    Makefile
    srcs_bonus/
      utile1_bonus.c
      utile2_bonus.c
      utile3_bonus.c
      utile4_bonus.c
  README.md
```

---

## The Dining Philosophers Problem

- **N philosophers** sit at a round table.
- Each philosopher alternates between **thinking**, **eating**, and **sleeping**.
- To eat, a philosopher needs to pick up **two forks** (one on each side).
- Forks are shared between neighbors, so philosophers must coordinate to avoid deadlocks (where everyone is waiting forever) and starvation (where a philosopher never gets to eat).

---

## How It Works

### philo (Mandatory Part)

- Each philosopher is represented by a **thread**.
- **Mutexes** are used to represent forks and to synchronize access to shared data.
- The program monitors philosophers to detect if any philosopher dies (does not eat within `time_to_die`).

### philo_bonus (Bonus Part)

- Each philosopher is represented by a **process**.
- **Semaphores** are used for fork management and synchronization.
- The logic is similar, but uses inter-process communication.

---

## Usage

### Build

#### philo

```sh
cd philo
make
```

#### philo_bonus

```sh
cd philo_bonus
make
```

### Run

Both versions take the same arguments:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Time (ms) a philosopher can go without eating before dying.
- `time_to_eat`: Time (ms) a philosopher spends eating.
- `time_to_sleep`: Time (ms) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers eat this many times, the simulation ends.

**Example:**

```sh
./philo 5 800 200 200
./philo 5 800 200 200 7
```

---

## Arguments

- All arguments must be **positive integers**.
- If the optional argument is not provided, the simulation ends when a philosopher dies.
- If provided, the simulation ends when all philosophers have eaten at least the specified number of times.

---

## Bonus Version

The `philo_bonus` directory contains a version using **processes** and **semaphores** instead of threads and mutexes. Usage and arguments are the same.

---

## Notes

- The project is written in C and uses only allowed standard libraries.
- Error handling is implemented for invalid arguments and resource allocation failures.
- The code is organized for clarity, with separate files for utility functions, data structures, and main logic.

---