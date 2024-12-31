/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/31 23:16:23 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_cmd1_operation(char *argv[], char *envp[], int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
        ft_perror("File Creation Failed", 3);
	dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    dup2(outfile, STDOUT_FILENO);
    close(outfile);
    execute(argv[2], envp);
    exit(0);
}

void    ft_cmd2_operation(char *argv[], char *envp[], int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
    	ft_perror("Open Failed", 4);
	}
	dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    dup2(infile, STDIN_FILENO);
    close(infile);
    execute(argv[3], envp);
	return ;
}

int     main(int argc, char *argv[], char *envp[])
{
    int     pipe_fd[2];
    int     infile;
    int     outfile;

    if (argc != 5)
    {
        ft_perror("Invalid input the input format is: ./pipex <file1> <cmd1> <cmd2> <file2>\n", -1);
        return (EXIT_FAILURE);
    }
}