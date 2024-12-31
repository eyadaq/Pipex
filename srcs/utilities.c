/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:00:48 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/31 22:36:18 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_perror(const char *msg, int errno)
{
	perror(msg);
	exit(errno);
}

void	close_on_exit(int *fds, int fd_count)
{
	int		i;

	i = 0;
	while (i < fd_count)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}

char 	**ft_get_paths(char *env[])
{
	int		i;
	char 		*path;
	char			**paths;
	
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
		ft_perror("PATH variable not found in the environment.\n", 9);
		exit(-1);
	}
	paths = ft_split((path + 5), ':');
	return (paths);
}

char	*ft_find_executable(char *envp[], char *cmd)
{
    int		i;
    char		*full_path;
    char		*temp;
    char			**paths;

	i = 0;
	paths = ft_get_paths(envp);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(temp, cmd);
        free(temp);
		if (access(full_path, X_OK) == 0)
        {
            ft_free_double(paths);
            return (full_path);
        }
        free(full_path);
        i++;
	}
	ft_free_double(paths);
    return (NULL);
}

int			execute(char *cmd, char *envp[])
{
	char 	*exec;
	char		**full_cmd;

	full_cmd = ft_split(cmd, ' ');
	exec = ft_find_executable(envp, full_cmd[0]); 
	execve(exec, full_cmd, envp);
	ft_perror("command not found", 10);
    free(exec);
	ft_free_double(full_cmd);
    return (-1);
}