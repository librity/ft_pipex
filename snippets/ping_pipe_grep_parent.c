/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_pipe_grep_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 15:05:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ping_pipe_grep_parent.c && ./a.out

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


#define CHILD_PROCESS_ID 0

static void	die(void)
{
	perror("\033[0;31mERROR!\033[0m");
	exit(EXIT_FAILURE);
}

static void	handle_child(int	pipe_descriptors[2])
{
	// Write the output of ping to STDOUT
	dup2(pipe_descriptors[1], STDOUT_FILENO);
	// Close file descriptors in child process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);
	// Executes ping
	execlp("ping", "ping", "-c", "5", "google.com", NULL);
}

static void	handle_parent(int	pipe_descriptors[2], int child_pid)
{
	// Write the output of ping to STDOUT
	dup2(pipe_descriptors[0], STDIN_FILENO);
	// Close file descriptors in child process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);
	// Executes ping
	execlp("grep", "grep", "rtt", NULL);
	// Wait for child process to finish executing
	waitpid(child_pid, NULL, 0);
}

int	main(int argc, char **argv)
{
	int	pipe_descriptors[2];
	int	child_pid;

	// Creates a pipe:
	// Bytes written on pipe_descriptors[1] can be read from pipe_descriptors[0]
	if (pipe(pipe_descriptors) == -1)
		die();

	// Creates a clone of this process
	child_pid = fork();
	if (child_pid < 0)
		die();

	if (child_pid == CHILD_PROCESS_ID)
		handle_child(pipe_descriptors);

	if (child_pid != CHILD_PROCESS_ID)
		handle_parent(pipe_descriptors, child_pid);

	return (EXIT_SUCCESS);
}
