/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:11:34 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/19 23:12:04 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/headers/libft.h"
#include <fcntl.h>

void                    ft_error(const char *s);
void                    ft_parent_operation();
void                    ft_child_operation();

#endif