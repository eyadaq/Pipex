/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/19 23:09:10 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int     main(int argc, char *argv[], char *envp[])
{
  int       pidid;
  int       fd[2];

  if (argc == 5)
  {
    pidid = fork();
    if (pidid == -1)
      ft_error("Fork didnt work");
    if (pidid == 0)
      ft_child_operation();
    ft_parent_operation();
    return (0);
  }
  else
  {
    ft_error("Invalid input the input should be Infile <CMD1> <CMD2> Oufile");
    return (0);
  }
}