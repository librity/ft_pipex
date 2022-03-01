/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   |_parent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 15:12:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc "|_parent.c" && ./a.out "ls" "wc"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD_PROCESS_ID 0

static void	die(void)
{
	perror("\033[0;31mERROR!\033[0m");
	exit(EXIT_FAILURE);
}

/*
** Closes pipe file descritors so processes don't hang.
*/
static void	close_pipes_fds(int pipe_fds[2])
{
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

/*
** Wait for child processes to finish executing.
*/
static void	wait_for_child(int left_pid)
{
	waitpid(left_pid, NULL, 0);
}

/*
** Creates a pipe... or dies trying ☠️.
** Bytes written on pipe_fds[1] can be read from pipe_fds[0].
*/
static int pipe_or_die(int pipe_fds[2])
{
	int pipe_return;

	pipe_return = pipe(pipe_fds);
	if (pipe_return < 0)
		die();
}

/*
** Creates a child process... or dies trying ☠️.
** The child process is almost identical to its parent,
** with a copy of its memory space at the time of fork.
*/
static int fork_or_die(void)
{
	int pid;

	pid = fork();
	if (pid < 0)
		die();
	return (pid);
}

/*
** Redirects the STDOUT of the current process to the pipe's input.
*/
static void	stdout_to_pipe(int pipe_fds[2])
{
	dup2(pipe_fds[1], STDOUT_FILENO);
}

/*
** Redirects the pipe's output to the STDIN of the current process.
*/
static void	pipe_to_stdin(int pipe_fds[2])
{
	dup2(pipe_fds[0], STDIN_FILENO);
}

/*
** Executes a file in PATH without any arguments.
*/
static void	execute_no_args(char *command)
{
	execlp(command, command, NULL);
}

static void	handle_child(int pipe_fds[2], char *left_command)
{
	stdout_to_pipe(pipe_fds);
	close_pipes_fds(pipe_fds);
	execute_no_args(left_command);
}

static void	handle_parent(int pipe_fds[2], char *right_command, int left_pid)
{
	pipe_to_stdin(pipe_fds);
	close_pipes_fds(pipe_fds);
	execute_no_args(right_command);
	wait_for_child(left_pid);
}

static void	handle_arguments(
				int argc,
				char **argv,
				char **left_command,
				char **right_command)
{
	if (argc != 3)
		die();
	*left_command = argv[1];
	*right_command = argv[2];
	printf("excuting \"%s | %s\"\n", *left_command, *right_command);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	char	*left_command;
	int		left_pid;
	char	*right_command;

	handle_arguments(argc, argv, &left_command, &right_command);
	pipe_or_die(pipe_fds);

	left_pid = fork_or_die();
	if (left_pid == CHILD_PROCESS_ID)
		handle_child(pipe_fds, left_command);

	if (left_pid != CHILD_PROCESS_ID)
		handle_parent(pipe_fds, right_command, left_pid);

	return (EXIT_SUCCESS);
}
