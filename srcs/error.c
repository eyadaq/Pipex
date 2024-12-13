/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:00:48 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/10 08:32:24 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int    ft_wrong_args()
{
   ft_putstr_fd("Invalid Number of Arguments\n", 2);
   return (-1); 
}

// t_bool      ft_check_files(char *file1, char *file2)
// {
   
// }