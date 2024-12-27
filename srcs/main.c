/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/27 15:02:25 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	ft_split_path(char *s, char *cmd)
{
	char	**pathes;

	pathes = ft_split(s, ' ');
	
}

char 	*ft_get_pathes(char *env[], char *cmd)
{
	int		i;
	char 	*path;
	
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break;
		}
		i++;
	}
	if (!env[i])
    {
        fprintf(stderr, "Error: PATH variable not found in the environment.\n");
        return;
    }
	ft_split_path(path, cmd);
}

// int           ft_child_operation(char *argv[], char *envp[], int *fd)
// {

// }

// int           ft_parent_operation(char *argv[], char *envp[], int *fd)
// {
 
// }

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
		ft_get_pathes(envp, envp[2]);
    //   ft_child_operation(argv, envp,fd);
    // waitpid(pidid, NULL, 0);
    // ft_parent_operation(argv, envp, fd);
    return (0);
  }
  else
  {
    ft_error("Invalid input the input should be Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
    return (0);
  }
}
