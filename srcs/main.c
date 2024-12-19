/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/20 01:18:49 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void         ft_child_operation(char *argv[], char *envp[], int *fd)
{
  int infile;

  infile = open(argv[1], O_RDONLY);
  if (-1 == infile)
    ft_error("Couldnt Read the Infile");
  
    /*
      * The child process will execute cmd1.
      * It will redirect its standard output (stdout) to the write end of the pipe using dup2.
      * This means that the output of cmd1 will be written to the pipe.
    */
}

void           ft_parent_operation(char *argv[], char *envp[], int *fd)
{
  int outfile;

  outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
  if (-1 == outfile)
    ft_error("Couldnt Create or Write to the Outfile");
    /*
      * The parent process will execute cmd2.
      * It will redirect its standard input (stdin) to the read end of the pipe using dup2.
      * This means that the input of cmd2 will come from the pipe.
    */
}

int     main(int argc, char *argv[], char *envp[])
{
  int       pidid;
  int       fd[2];

  if (argc == 5)
  {
    if (pipe(fd) == -1)
      ft_error("Pipe Failed");
    pidid = fork();
    if (pidid == -1)
      ft_error("Fork Failed");
    if (pidid == 0)
      ft_child_operation(argv, envp,fd);
    waitpid(pidid, NULL, 0);
    ft_parent_operation(argv, envp, fd);
    return (0);
  }
  else
  {
    ft_error("Invalid input the input should be Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
    return (0);
  }
}
