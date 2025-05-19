# 🔗 Pipex
  ![Pipex](pipexm.png)
## 📌 Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Mandatory Features](#mandatory-features)
- [Compilation](#compilation)
- [Execution](#execution)
- [Example](#example)
- [Implementation Overview](#implementation-overview)
- [Resources](#resources)

---

## 🧩 Introduction

**Pipex** is a 42 school project that aims to make you understand how Unix pipes work and how processes communicate with each other. You’ll be building a small shell-like program that mimics the behavior of:

```bash
< infile cmd1 | cmd2 > outfile
````

---

## 🎯 Project Objectives

* Learn how to work with **file descriptors**.
* Understand and implement **pipes** for IPC (inter-process communication).
* Work with **child processes** using `fork()`.
* Execute external programs with `execve()`.
* Handle **input/output redirection** properly.

---

## ✅ Mandatory Features

Your program must reproduce the shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Where:

* `infile` is a file that exists and is readable.
* `cmd1` takes input from `infile`.
* `cmd2` takes input from the output of `cmd1`.
* `outfile` is created (or overwritten) with the output of `cmd2`.

Requirements:

* Use only `open()`, `read()`, `write()`, `close()`, `dup()`, `dup2()`, `pipe()`, `fork()`, `execve()`, `waitpid()`, `access()`, `perror()`, `strerror()`, `exit()`.
* No usage of `printf()` or `malloc()` outside of your own implementation (`libft`).
* Handle command not found, permission denied, and missing file errors.

---

## 🛠 Compilation

To compile the project, simply run:

```bash
make
```

This will generate an executable named `pipex`.

To clean up object files:

```bash
make clean
```

To remove everything including the executable:

```bash
make fclean
```

To recompile everything from scratch:

```bash
make re
```

---

## 🚀 Execution

Usage:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Make sure to wrap commands in quotes if they include flags or arguments.

---

## 💡 Example

Assuming `infile` contains:

```
Hello World
```

Run:

```bash
./pipex infile "cat" "wc -w" outfile
```

The `cat` command reads from `infile` and passes it to `wc -w`, which counts words. The result is saved in `outfile`.

---

## 🧠 Implementation Overview

* **Argument Parsing**: Validate and extract command-line arguments.
* **Environment**: Extract `PATH` from `envp` to locate command binaries.
* **Pipe Setup**: Create a pipe with `pipe()`.
* **Forking**: Create child processes for `cmd1` and `cmd2`.
* **Redirection**: Use `dup2()` to redirect input/output.
* **Execution**: Use `execve()` to run each command.
* **Error Handling**: Use `perror()` or custom messages to report issues.

---

## 📚 Resources

* `man fork`, `man execve`, `man pipe`, `man dup2`, `man access`
* Unix programming guides
* [42 Docs](https://harm-smits.github.io/42docs/projects/pipex)

---

> 🛠 Developed as part of the 42 Network curriculum to master Unix piping and process handling.

```
