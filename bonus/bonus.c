/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:47:40 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/13 08:04:09 by eaqrabaw         ###   ########.fr       */
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

void	ft_bonus_cmd1_operation(int	infile, char *arg, char **envp)
{
	if (infile < 0)
		ft_perror("Open Failed", 1);
	
}

void	ft_bonus_cmd2_operation(int	outfile, char *arg, char **envp)
{
	if (outfile < 0)
		ft_perror("File Creation Failed", 1);

}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_in;
	int		fd_out;
	int		fd_input;
	int		i;
	pid_t 	pid;

	if (argc < 5)
		ft_perror("Invalid input",4242);
	fd_in = get_fd(argv[1], 0);
	fd_out = get_fd(argv[argc - 1], 1);
}
