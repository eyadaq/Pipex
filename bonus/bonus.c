/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:47:40 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/02/13 07:49:17 by eaqrabaw         ###   ########.fr       */
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


