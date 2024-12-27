/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:00:48 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/27 14:33:44 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_error(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

// void    ft_get_path(char *env[], int file)
// {
//     int     i;
//     char    **pathes;
//     char    *path_value;

//     i = 0;
//     while (env[i])
//     {
//         if (strncmp(env[i], "PATH=", 5) == 0)
//         {
//             path_value = env[i];
//             break;
//         }
//         i++;
//     }
//     if (!env[i])
//     {
//         fprintf(stderr, "Error: PATH variable not found in the environment.\n");
//         return;
//     }
//     pathes = ft_split(path_value, ':');
//     i = 0;
//     while (pathes[i])
//         free(pathes[i++]);
//     free(pathes);
// }


