/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:11:34 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/28 02:50:07 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/headers/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

void           ft_child_operation(char *argv[], char *envp[], int *fd);
void           ft_parent_operation(char *argv[], char *envp[], int *fd);
void           ft_perror(const char *msg, int errno);
char 	       **ft_get_paths(char *env[]);
char	       *ft_find_executable(char *envp[], char *cmd);
int	           execute(char *cmd, char *envp[]);

#endif