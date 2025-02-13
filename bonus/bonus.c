/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:47:40 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/13 07:42:02 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int get_fd(char *file, int mode)
{
	int fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		ft_perror("Error opening file", 1);
	return fd;
}

void execute_b(char *cmd, char **envp)
{
	char *args[] = {"/bin/sh", "-c", cmd, NULL};
	execve("/bin/sh", args, envp);
	perror("Execution failed");
	exit(127); // Exit with failure but don't terminate pipeline
}

void child_process_1(char *cmd, char **envp, int input_fd, int pipe_fd)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd, STDOUT_FILENO);
	close(input_fd);
	close(pipe_fd);
	execute_b(cmd, envp);
	exit(127);
}

void child_process_2(char *cmd, char **envp, int input_fd, int output_fd)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(input_fd);
	close(output_fd);
	execute_b(cmd, envp);
	exit(127);
}

int pipe_and_fork(char *cmd, char **envp, int input_fd)
{
	int pipefd[2];
	pid_t pid;

	if (pipe(pipefd) == -1)
		ft_perror("Pipe failed", 2);
	pid = fork();
	if (pid == -1)
		ft_perror("Fork failed", 2);
	if (pid == 0)
	{
		close(pipefd[0]);
		child_process_1(cmd, envp, input_fd, pipefd[1]);
	}
	close(pipefd[1]);
	close(input_fd);
	return pipefd[0];
}

int main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		ft_perror("Invalid number of arguments", 4242);

	int fd_in = get_fd(argv[1], 0);
	int fd_out = get_fd(argv[argc - 1], 1);
	int input_fd = fd_in;
	int i = 2;

	while (i < argc - 2)
		input_fd = pipe_and_fork(argv[i++], envp, input_fd);

	pid_t final_pid = fork();
	if (final_pid == -1)
		ft_perror("Fork failed", 2);
	if (final_pid == 0)
		child_process_2(argv[argc - 2], envp, input_fd, fd_out);
	close(input_fd);
	close(fd_out);
	while (wait(NULL) > 0);
	return 0;
}

