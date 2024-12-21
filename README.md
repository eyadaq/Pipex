# Pipex Project

![Pipex](pipexm.png)

The Pipex project is a 42 school project that aims to recreate the behavior of the shell pipeline command `|`. The program takes four arguments:

1. `file1`: The input file.
2. `cmd1`: The first command to execute.
3. `cmd2`: The second command to execute.
4. `file2`: The output file.

The program executes `cmd1` with `file1` as input, passes the output of `cmd1` as input to `cmd2`, and writes the output of `cmd2` to `file2`.

## Usage

```sh
./pipex file1 cmd1 cmd2 file2