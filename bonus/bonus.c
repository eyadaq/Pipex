/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:47:40 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/12 11:35:20 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_fd(char *file, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_perror("Error opening the file", 1);
	}
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ft_perror("Error opening the file", 1);
	}
	return (fd);
}

int	pipe_and_fork(char *cmd, char **envp, int input_fd)
{
	int	pipefd[2];
	pid_t pid;

	if (pipe(pipefd) == -1)
		ft_perror("Pipe failed", 2);
	pid = fork();
	if (pid == -1)
		ft_perror("Fork failed", 2);
	if (pid == 0) // Child process
	{
		close(pipefd[0]); // Close unused read end
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(input_fd);
		close(pipefd[1]);
		execute(cmd, envp);
		exit(1);
	}
	else // Parent process
	{
		close(pipefd[1]); // Close unused write end
		close(input_fd);  // Close old input
		waitpid(pid, NULL, 0);
		return (pipefd[0]); // New input for next command
	}
	return (-1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_in;
	int		fd_out;
	int		i;
	int		input_fd;

	if (argc < 5)
		ft_perror("Invalid number of arguments", 1);
	fd_in = get_fd(argv[1], 0);
	fd_out = get_fd(argv[argc - 1], 1);
	input_fd = fd_in;
	i = 2;
	while(i < argc - 2)
		input_fd = pipe_and_fork(argv[i++], envp, input_fd);
	pid_t pid = fork();
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(input_fd);
		close(fd_out);
		execute(argv[argc - 2], envp);
		exit(1);
	}
	close(input_fd);
	close(fd_out);
	waitpid(pid, NULL, 0);
	return (0);
}

