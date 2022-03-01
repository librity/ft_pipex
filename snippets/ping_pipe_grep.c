/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_pipe_grep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 22:35:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ping_pipe_grep.c && ./a.out

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

static void	ping_google(int	pipe_descriptors[2])
{
	// Write the output of ping to STDOUT
	dup2(pipe_descriptors[1], STDOUT_FILENO);
	// Close file descriptors in child process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);
	// Executes ping
	execlp("ping", "ping", "-c", "5", "google.com", NULL);
}

static void	grep_rtt(int	pipe_descriptors[2])
{
	// Write the output of ping to STDOUT
	dup2(pipe_descriptors[0], STDIN_FILENO);
	// Close file descriptors in child process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);
	// Executes ping
	execlp("grep", "grep", "rtt", NULL);
}

int	main(int argc, char **argv)
{
	int	pipe_descriptors[2];
	int	ping_pid;
	int	grep_pid;

	// Creates a pipe:
	// Bytes written on pipe_descriptors[1] can be read from pipe_descriptors[0]
	if (pipe(pipe_descriptors) == -1)
		die();

	// Creates a clone of this process
	ping_pid = fork();
	if (ping_pid < 0)
		die();

	if (ping_pid == CHILD_PROCESS_ID)
		ping_google(pipe_descriptors);

	grep_pid = fork();
	if (grep_pid < 0)
		die();

	if (grep_pid == CHILD_PROCESS_ID)
		grep_rtt(pipe_descriptors);

	// Close file descriptors in parent process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);

	// Wait for child processes to finish executing
	waitpid(ping_pid, NULL, 0);
	waitpid(grep_pid, NULL, 0);

	return (EXIT_SUCCESS);
}
