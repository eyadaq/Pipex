/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/28 02:03:12 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_child_operation(char *argv[], char *envp[], int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
        ft_perror("Open Failed");
	dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    dup2(outfile, STDOUT_FILENO);
    close(outfile);
    execute(argv[2], &argv[2], envp);
    return;
}

void    ft_parent_operation(char *argv[], char *envp[], int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
    	ft_perror("Open Failed");
	dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    dup2(infile, STDIN_FILENO);
    close(infile);
    execute(argv[3], &argv[3], envp);
	return ;
}

int     main(int argc, char *argv[], char *envp[])
{
    int pidid;
    int fd[2];

    if (argc == 5)
    {
        if (pipe(fd) == -1)
            ft_perror("Pipe Failed");
        pidid = fork();
        if (pidid == -1)
            ft_perror("Fork Failed");
        if (pidid == 0)
        {
            ft_child_operation(argv, envp, fd);
        }
        else
        {
            ft_parent_operation(argv, envp, fd);
            waitpid(pidid, NULL, 0);
        }
        return (0);
    }
    else
    {
        ft_error("Invalid input the input format is: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
        return (0);
    }
}
