/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:11:34 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/13 21:25:07 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/headers/libft.h"
#include <fcntl.h>

typedef struct s_operation
{
    char    *infile;
    char    *outfile;
    char    *cmd1;
    char    *cmd2;
}                   t_operation;
//----------------------Error----------------------------------------------------------------------
int             ft_wrong_args();


#endif