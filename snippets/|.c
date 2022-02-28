/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   |.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 21:13:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc "|.c" && ./a.out

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


// TODO: Run to piped commands from argv
int	main(int argc, char **argv, char **envp)
{
	int	pipe_descriptors[2];

	char *left_command;
	int	left_pid;

	char *right_command;
	int	right_pid;

	if (argc != 3)
		die();

	// Creates a pipe:
	// Bytes written on pipe_descriptors[1] can be read from pipe_descriptors[0]
	if (pipe(pipe_descriptors) == -1)
		die();

	// Creates a clone of this process
	left_pid = fork();
	if (left_pid < 0)
		die();

	if (left_pid == CHILD_PROCESS_ID)
		ping_google(pipe_descriptors);

	right_pid = fork();
	if (right_pid < 0)
		die();

	if (right_pid == CHILD_PROCESS_ID)
		grep_rtt(pipe_descriptors);

	// Close file descriptors in parent process
	close(pipe_descriptors[0]);
	close(pipe_descriptors[1]);

	// Wait for child processes to finish executing
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, NULL, 0);

	return (EXIT_SUCCESS);
}
