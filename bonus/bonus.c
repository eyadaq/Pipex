/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:47:40 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/13 09:39:54 by eaqrabaw         ###   ########.fr       */
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
	return fd;
}

void	ft_bonus_cmd1_operation(int	pipe_fd[],int fd[], char *arg, char **envp)
{
	if (fd[In] < 0)
		ft_perror("Open Failed", 1);
	dup2(fd[In], STDIN_FILENO);
	dup2(pipe_fd[Out], STDOUT_FILENO);
	close(pipe_fd[In]);
	close(pipe_fd[Out]);
	close(fd[In]);
}

void	ft_bonus_cmd2_operation(int	pipe_fd[], int fd[],char *arg, char **envp)
{
	if (pipe_fd[Out] < 0)
		ft_perror("File Creation Failed", 1);
	dup2(pipe_fd[In] , STDIN_FILENO);
	dup2(pipe_fd[Out], STDOUT_FILENO);
	close(pipe_fd[In]);
	close(pipe_fd[Out]);

}

int	main(int argc, char *argv[], char *envp[])
{
	int 	fd[2];
	int		pipe_fd[2];
	int		i;
	pid_t 	pid;

	if (argc < 5)
		ft_perror("Invalid input",4242);
	fd[In] = get_fd(argv[1], 0);
	fd[Out] = get_fd(argv[argc - 1], 1);
	if (pipe(pipe_fd) == -1)
		ft_perror("pipe failed", 1);
}
