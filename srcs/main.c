/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/01 00:38:06 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror(const char *msg, int err_code)
{
    perror(msg);
    exit(err_code);
}

void	ft_cmd1_operation(char *argv[], char *envp[], int pipe_fd[])
{
    int infile;

    infile = open(argv[1], O_RDONLY);
    if (infile < 0)
        ft_perror("Open Failed", 4);
    dup2(infile, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[0]);
    close(infile);
    execve(argv[2], &argv[2], envp);
    ft_perror("Execve Failed", 5);
}

void	ft_cmd2_operation(char *argv[], char *envp[], int pipe_fd[])
{
    int outfile;

    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0)
        ft_perror("File Creation Failed", 3);
    dup2(pipe_fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(pipe_fd[1]);
    close(outfile);
    execve(argv[3], &argv[3], envp);
    ft_perror("Execve Failed", 5);
}

int	main(int argc, char *argv[], char *envp[])
{
    int pipe_fd[2];
    int     pid1;
    int      pid2;

    if (argc != 5)
    {
        ft_perror("Invalid input the input format is: ./pipex <file1> <cmd1> <cmd2> <file2>\n", -1);
        return (EXIT_FAILURE);
    }
    if (pipe(pipe_fd) == -1)
        ft_perror("Pipe Failed", 2);
    pid1 = fork();
    if (pid1 == -1)
        ft_perror("Fork Failed", 1);
    if (pid1 == 0)
        ft_cmd1_operation(argv, envp, pipe_fd);
    pid2 = fork();
    if (pid2 == -1)
        ft_perror("Fork Failed", 1);
    if (pid2 == 0)
        ft_cmd2_operation(argv, envp, pipe_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (EXIT_SUCCESS);
}
