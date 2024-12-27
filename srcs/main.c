/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/28 00:51:24 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int           ft_child_operation(char *argv[], char *envp[], int *fd)
{
	int		
}

int           ft_parent_operation(char *argv[], char *envp[], int *fd)
{
 
}

int     main(int argc, char *argv[], char *envp[])
{
  int       pidid;
  int       fd[2];

  if (argc == 5)
  {
	if (pipe(fd) == -1)
	  ft_perror("Pipe Failed");
	pidid = fork();
	if (pidid == -1)
	  ft_perror("Fork Failed");
	if (pidid == 0)
	
	return (0);
  }
  else
  {
	ft_error("Invalid input the input should be Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	return (0);
  }
}
