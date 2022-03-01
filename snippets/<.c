/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:20:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 22:24:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc "<.c" && ./a.out infile "wc"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define CHILD_PROCESS_ID 0
#define OPEN_FLAGS O_RDONLY

static void	die(void)
{
	perror("ERROR!\n");
	exit(EXIT_FAILURE);
}

static int open_file_or_die(char *filename)
{
	int open_fd;

	open_fd = open(filename, OPEN_FLAGS);
	if (open_fd < 0)
		die();
	return (open_fd);
}

static void	file_to_stdin(int infile_fd)
{
	dup2(infile_fd, STDIN_FILENO);
}

static void	execute_no_args(char *command)
{
	execlp(command, command, NULL);
}

static void	handle_arguments(
				int argc,
				char **argv,
				char **infile,
				char **command)
{
	if (argc != 3)
		die();
	*infile = argv[1];
	*command = argv[2];
	printf("excuting \"< %s %s\"\n", *infile, *command);
}

int	main(int argc, char **argv, char **envp)
{
	char *infile;
	int infile_fd;
	char *command;

	handle_arguments(argc, argv, &infile, &command);

	infile_fd = open_file_or_die(infile);
	file_to_stdin(infile_fd);
	execute_no_args(command);

	close(infile_fd);
	return (EXIT_SUCCESS);
}
