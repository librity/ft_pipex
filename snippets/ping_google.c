/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_google.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 23:50:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ping_google.c && ./a.out

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

static void	ping_google(void)
{
	execlp("ping", "ping", "-c", "5", "google.com", NULL);
}

int	main(int argc, char **argv)
{
	int	pipe_descriptors[2];
	int	ping_pid;

	if (pipe(pipe_descriptors) == -1)
		die();

	ping_pid = fork();
	if (ping_pid < 0)
		die();

	if (ping_pid == CHILD_PROCESS_ID)
		ping_google();
	waitpid(ping_pid, NULL, 0);

	return (EXIT_SUCCESS);
}
