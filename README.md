# 🍴 Philosophers - Dining Philosophers Problem

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()
[![Build](https://img.shields.io/badge/Build-Passing-success.svg)]()
[![Version](https://img.shields.io/badge/Version-1.0.0-blue.svg)]()

<div align="center">

# 🍴 Philosophers

> A simulation of the classic Dining Philosophers Problem using C, with both thread-based and process-based solutions.

**Master concurrency, synchronization, and deadlock avoidance!**

[![GitHub stars](https://img.shields.io/github/stars/yourusername/philosophers-42?style=social)](https://github.com/yourusername/philosophers-42/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/philosophers-42?style=social)](https://github.com/yourusername/philosophers-42/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/philosophers-42)](https://github.com/yourusername/philosophers-42/issues)

</div>

---

## 📚 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [🛠️ Installation](#️-installation)
- [🚀 Usage](#-usage)
- [📁 Project Structure](#-project-structure)
- [🧪 Testing](#-testing)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

---

## 🎯 Overview

This project implements the **Dining Philosophers Problem** in C, providing two solutions:
- `philo`: Uses threads and mutexes.
- `philo_bonus`: Uses processes and semaphores.

The goal is to simulate philosophers sitting at a table, alternating between thinking, eating, and sleeping, while sharing forks (resources) and avoiding deadlocks and starvation.

---

## ✨ Features

- Multi-philosopher simulation
- Thread-based (mutex) and process-based (semaphore) solutions
- Deadlock and starvation avoidance
- Real-time status output (eating, sleeping, thinking, death)
- Configurable simulation parameters via command-line

---

## 🛠️ Installation

### Prerequisites

- **C compiler** (GCC recommended)
- **Make** (optional, if using provided Makefile)
- **Linux/macOS** (tested on Ubuntu and macOS)

### 🏗️ Building the Project

#### For `philo` (threads & mutexes):

```bash
cd philo
make
```

#### For `philo_bonus` (processes & semaphores):

```bash
cd philo_bonus
make
```

---

## 🚀 Usage

### Starting the Simulation

Both versions take the same arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Time (ms) a philosopher can go without eating before dying.
- `time_to_eat`: Time (ms) a philosopher spends eating.
- `time_to_sleep`: Time (ms) a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers eat this many times, the simulation ends.

**Example:**

```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

---

## 📁 Project Structure

```
philosophers-42/
├── philo/
│   ├── includes/
│   │   ├── philo.h
│   │   └── structs.h
│   ├── main.c
│   ├── Makefile
│   └── srcs/
│       ├── utile1.c
│       ├── utile2.c
│       ├── utile3.c
│       └── utile4.c
├── philo_bonus/
│   ├── includes/
│   │   ├── philo_bonus.h
│   │   └── structs_bonus.h
│   ├── main.c
│   ├── Makefile
│   └── srcs_bonus/
│       ├── utile1_bonus.c
│       ├── utile2_bonus.c
│       ├── utile3_bonus.c
│       └── utile4_bonus.c
└── README.md
```

---

## 🧪 Testing

### Manual Testing

- Run the simulation with different arguments and observe the output.
- Try edge cases (e.g., 1 philosopher, very short `time_to_die`, etc.).
- Check for deadlocks and starvation (no philosopher should starve if parameters are reasonable).

---

## 🤝 Contributing

This is a 42 School project, but if you have suggestions or find bugs, feel free to contribute:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Commit and push
5. Open a Pull Request

---

## 📄 License

This project is part of the 42 School curriculum. The code is written for educational purposes.

---

<div align="center">

**Made with ❤️ and lots of ☕**

*Master concurrency, synchronization, and deadlock avoidance!*

[![GitHub stars](https://img.shields.io/github/stars/yourusername/philosophers-42?style=social)](https://github.com/yourusername/philosophers-42/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/philosophers-42?style=social)](https://github.com/yourusername/philosophers-42/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/philosophers-42)](https://github.com/yourusername/philosophers-42/issues)

**Author**: [Your Name]  
**School**: 42 School  
**Project**: Philosophers  
**Last updated**: 2024

</div>

--- 