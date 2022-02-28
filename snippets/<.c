/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 21:12:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc "<.c" && ./a.out

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD_PROCESS_ID 0

static void	die(void)
{
	perror("ERROR!\n");
	exit(EXIT_FAILURE);
}

// TODO: Pipe a file to a command's STDIN and run it
int	main(int argc, char **argv, char **envp)
{

}
