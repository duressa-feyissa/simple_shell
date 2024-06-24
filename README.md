# Simple Shell

## Overview

The Simple Shell project is an implementation of a basic command-line shell. It allows users to interact with the operating system by executing commands, navigating the file system, and performing various shell operations. This project demonstrates fundamental concepts of system programming, process management, and input/output handling in a Unix-like environment.

## Features

- **Command Execution**: Execute built-in commands as well as system programs.
- **Input Handling**: Read and parse user input from the command line.
- **Environment Variables**: Support for environment variables.
- **File System Navigation**: Commands for navigating the file system (e.g., `cd`, `pwd`).
- **Process Management**: Handle foreground and background processes.
- **Error Handling**: Basic error handling for invalid commands and arguments.

## Getting Started

### Prerequisites

- Unix-like operating system (e.g., Linux, macOS)
- GCC compiler

### Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/duressa-feyissa/simple_shell.git
    cd simple_shell
    ```

2. **Compile the source code**:
    ```sh
    gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
    ```

3. **Run the shell**:
    ```sh
    ./simple_shell
    ```

## Usage

Once the shell is running, you can start typing commands. For example:

- **List files**: `ls`
- **Print working directory**: `pwd`
- **Change directory**: `cd /path/to/directory`
- **Print environment variables**: `env`
- **Exit the shell**: `exit`

## Built-In Commands

- `cd [directory]`: Change the current directory to the specified directory.
- `pwd`: Print the current working directory.
- `env`: Display all environment variables.
- `exit`: Exit the shell.

