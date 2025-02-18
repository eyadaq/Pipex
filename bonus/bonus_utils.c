/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:16:03 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/12 10:01:31 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror(char *msg, int errno)
{
	if (errno == 4242)
	{
		ft_putstr_fd(msg, 2);
		exit(1);
	}
	else
	{
		perror(msg);
		exit(errno);
	}
}

void	close_on_exit(int *fds, int fd_count)
{
	int	i;

	i = 0;
	while (i < fd_count)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}

char	**ft_get_paths(char *env[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break ;
		}
		i++;
	}
	if (!env[i])
	{
		ft_perror("PATH variable not found in the environment.\n", 9);
		exit(-1);
	}
	paths = ft_split((path + 5), ':');
	if (!paths)
		ft_perror("Failed to split PATH variable.\n", 9);
	return (paths);
}

char	*ft_find_executable(char *envp[], char *cmd)
{
	int		i;
	char	*full_path;
	char	*temp;
	char	**paths;

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

int	execute(char *cmd, char *envp[])
{
	char	*exec;
	char	**full_cmd;

	full_cmd = ft_split(cmd, ' ');
	if (!full_cmd || !full_cmd[0])
	{
		ft_free_double(full_cmd);
		ft_perror("command not found", 127);
	}
	if (access(full_cmd[0], X_OK) == 0)
		exec = ft_strdup(full_cmd[0]);
	else
		exec = ft_find_executable(envp, full_cmd[0]);
	if (!exec)
	{
		ft_free_double(full_cmd);
		ft_perror("command not found", 127);
	}
	execve(exec, full_cmd, envp);
	ft_perror("Execve Failed", 5);
	free(exec);
	ft_free_double(full_cmd);
	return (-1);
}
