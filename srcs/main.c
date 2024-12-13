/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/13 21:51:59 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int     main(int argc, char *argv[])
{
    t_operation  *operation;

    operation = malloc(sizeof(t_operation));
    if (!operation)
        return (-1);
    if (argc != 5)
        return (ft_wrong_args());
    operation->infile = argv[1];
    operation->cmd1 = argv[2];
    operation->cmd2 = argv[3];
    operation->outfile = argv[4];
    ft_printf("Infile = %s, Cmd-1 = %s, Cmd-2 = %s, Outfile = %s\n", operation->infile, operation->cmd1,operation->cmd2, operation->outfile);
    pid_t pid;

  //create child process
  pid = fork();

  if (pid == 0)
  {
    //inside child process
    printf("I am the child process\n");

    pid_t pidchild;
    //get process id
    pidchild = getpid();

    printf("My id is %d\n", pidchild);
  }
  else if (pid > 0)
  {
    //inside parent process
    printf("I am the parent process\n");

    pid_t pidpar;

    pidpar = getpid();

    printf("My id is %d\n", pidpar);

  }
    return (0);
}