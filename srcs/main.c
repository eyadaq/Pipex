/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:16 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/10 08:31:55 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int     main(int argc, char *argv[])
{
    char    *infile;
    char    *outfile;
    char    *cmd1;
    char    *cmd2;
    
    if (argc != 5)
        return (ft_wrong_args());
    infile = argv[1];
    cmd1 = argv[2];
    cmd2 = argv[3];
    outfile = argv[4];
    ft_printf("ThE Infile = %s, THe Cmd 1 = %s, cmd2 is = %s, the outfile = %s\n", infile, cmd1, cmd2, outfile);

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