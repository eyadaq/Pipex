/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/31 23:23:17 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_cmd1_operation(char *argv[], char *envp[], int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
        ft_perror("File Creation Failed", 3);
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
	return ;
}
/*
The first child handles reading from the input (or file) and executing the first command.
The second child takes the output of the first child (via the pipe) as input and writes its result to the designated output (or file).
*/
void    first_child(char *argv[], char *envp[])
{
    int     pidid;

    pidid = fork();
    if (pidid = -1)
    {
        ft_perror("Fork Failed!", 1);
    }
    if (pidid == 0)
    {
        
    }
}

void    second_child(char *argv[], char *envp[])
{
    int     pidid;

    pidid = fork();
    if (pidid = -1)
    {
        ft_perror("Fork Failed!", 1);
    }
    if (pidid == 0)
    {
        
    }
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