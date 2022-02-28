/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   |_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 13:17:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc "|_execve.c" && ./a.out "ls" "wc"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD_PROCESS_ID 0

char **g_env_vars;

static void	die(void)
{
	perror("ERROR!\n");
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
static void	wait_for_children(int left_pid, int right_pid)
{
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, NULL, 0);
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
static void	execute_or_die(char *command)
{
	int execve_return;


	execve_return = execve(command, command, g_env_vars);
	if (execve_return < 0)
		die();
}

static void	run_left(int pipe_fds[2], char *left_command)
{
	stdout_to_pipe(pipe_fds);
	close_pipes_fds(pipe_fds);
	execute_or_die(left_command);
}

static void	run_right(int pipe_fds[2], char *right_command)
{
	pipe_to_stdin(pipe_fds);
	close_pipes_fds(pipe_fds);
	execute_or_die(right_command);
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

// TODO: HANDLE COMMAND ARGUMENTS WITH ft_split.
int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	char	*left_command;
	int		left_pid;
	char	*right_command;
	int		right_pid;

	handle_arguments(argc, argv, &left_command, &right_command);
	g_env_vars = envp;
	pipe_or_die(pipe_fds);

	left_pid = fork_or_die();
	if (left_pid == CHILD_PROCESS_ID)
		run_left(pipe_fds, left_command);

	right_pid = fork_or_die();
	if (right_pid == CHILD_PROCESS_ID)
		run_right(pipe_fds, right_command);

	close_pipes_fds(pipe_fds);
	wait_for_children(left_pid, right_pid);

	return (EXIT_SUCCESS);
}
