/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:11:34 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/31 23:24:41 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/headers/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

void           ft_cmd1_operation(char *argv[], char *envp[], int *fd);
void           first_child(char *argv[], char *envp[]);
void           second_child(char *argv[], char *envp[]);
void           ft_cmd2_operation(char *argv[], char *envp[], int *fd);
void           ft_perror(const char *msg, int errno);
char 	       **ft_get_paths(char *env[]);
char	       *ft_find_executable(char *envp[], char *cmd);
int	           execute(char *cmd, char *envp[]);
void	       close_on_exit(int *fds, int fd_count);


#endif