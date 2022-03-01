/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   >.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 22:35:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ">.c" && ./a.out "ls" outfile

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define CHILD_PROCESS_ID 0
#define CREATE_FLAGS O_CREAT|O_WRONLY|O_TRUNC
#define CREATE_PERMISSION 0000664

static void	die(void)
{
	perror("\033[0;31mERROR!\033[0m");
	exit(EXIT_FAILURE);
}

static int create_file_or_die(char *filename)
{
	int open_fd;

	open_fd = open(filename, CREATE_FLAGS, CREATE_PERMISSION);
	if (open_fd < 0)
		die();
	return (open_fd);
}

static int close_file_or_die(int close_fd)
{
	close_fd = close(close_fd);
	if (close_fd < 0)
		die();
	return (close_fd);
}

static void	stdout_to_file(int outfile_fd)
{
	dup2(outfile_fd, STDOUT_FILENO);
}

static void	execute_no_args(char *command)
{
	execlp(command, command, NULL);
}

static void	handle_arguments(
				int argc,
				char **argv,
				char **command,
				char **outfile)
{
	if (argc != 3)
		die();
	*command = argv[1];
	*outfile = argv[2];
	printf("excuting \"%s > %s\"\n", *command, *outfile);
}

int	main(int argc, char **argv, char **envp)
{
	char *command;
	char *outfile;
	int outfile_fd;

	handle_arguments(argc, argv, &command, &outfile);

	outfile_fd = create_file_or_die(outfile);
	stdout_to_file(outfile_fd);
	execute_no_args(command);

	close_file_or_die(outfile_fd);
	return (EXIT_SUCCESS);
}
