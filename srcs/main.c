/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/22 23:33:06 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_child_operation(char *argv[], char *envp[], int *fd)
{
  int infile;
	 
	infile = open(fd[0], O_RDONLY, 0555);
  if (fd == -1)
  {
    ft_error("Reading the file");
    return (fd);   
  }
  return (fd);
}

int           ft_parent_operation(char *argv[], char *envp[], int *fd)
{
  int outfile;
	 
	outfile =open(fd[0], O_RDONLY, 0555);
  if (fd == -1)
  {
    ft_error("Writing or creating the file");
    return (fd);   
  }
  return (fd);
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
