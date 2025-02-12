/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/12 07:46:32 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_cmd1_operation(char *argv[], char *envp[], int pipe_fd[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close_on_exit(pipe_fd, 2);
		ft_perror("Open Failed", 1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	execute(argv[2], envp);
}

void	ft_cmd2_operation(char *argv[], char *envp[], int pipe_fd[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close_on_exit(pipe_fd, 2);
		ft_perror("File Creation Failed", 1);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pipe_fd[2];
	int	pid[2];
	int	status;

	if (argc != 5)
		ft_perror("Input format:./pipex <file1> <cmd1> <cmd2> <file2>\n", 4242);
	if (pipe(pipe_fd) == -1)
		ft_perror("Pipe Failed", 2);
	pid[0] = fork();
	if (pid[0] == -1)
		ft_perror("Fork Failed", 1);
	if (pid[0] == 0)
		ft_cmd1_operation(argv, envp, pipe_fd);
	pid[1] = fork();
	if (pid[1] == -1)
		ft_perror("Fork Failed", 1);
	if (pid[1] == 0)
		ft_cmd2_operation(argv, envp, pipe_fd);
	close_on_exit(pipe_fd, 2);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128 + WTERMSIG(status));
}
