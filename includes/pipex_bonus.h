/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:30:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 10:32:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <defines_bonus.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_file
{
	char	*path;
	int		fd;
}		t_file;

typedef struct s_exec
{
	char	*raw;
	char	**tokens;
	char	*cmd;
	char	*path;

	int		code;
}		t_exec;

typedef struct s_pipex
{
	int		argc;
	int		arg;
	char	**argv;

	char	**envp;
	char	*path;
	char	**paths;

	char	*limiter;
	char	*last_cmd;

	t_file	infile;
	t_file	outfile;

	t_list	*free_me;
}		t_pipex;

int		nex(int argc, char **argv, char **envp);
int		hdoc(int argc, char **argv, char **envp);

/******************************************************************************\
 * INITIALIZERS
\******************************************************************************/

void	initialize_control(t_pipex *ctl, int argc, char **argv, char **envp);
void	initialize_hdoc(t_pipex *ctl);
void	initialize_nex(t_pipex *ctl);

void	initialize_environment(t_pipex *ctl);

/******************************************************************************\
 * CHILDREN
\******************************************************************************/

pid_t	fork_or_die(void);

void	get_hdoc(t_pipex *ctl);
void	handle_child(t_pipex *ctl, char *raw_cmd);

/******************************************************************************\
 * COMMANDS
\******************************************************************************/

void	command_or_die(t_pipex *ctl, char *raw_cmd);

char	*get_clean_path_or_die(char **envp);
char	**get_paths_or_die(char **envp);

char	*find_executable(char *command, char **paths);
char	*find_executable_or_die(char *command, char **paths);

char	**split_command_or_die(char *raw_command);
char	**tokenize_or_die(char *raw_command);

void	execute_or_die(t_pipex *ctl, char *raw_cmd);

/******************************************************************************\
 * FILES
\******************************************************************************/

int		create_file_or_die(char *path);
int		open_file_or_die(char *path);
int		close_or_die(int close_me);

int		open_infile_or_die(t_pipex *ctl);
int		create_outfile_or_die(t_pipex *ctl);
int		open_outfile_or_die(t_pipex *ctl);

/******************************************************************************\
 * PIPES
\******************************************************************************/

void	pipe_or_die(int pipe_fds[2]);
void	close_pipe(int pipe_fds[2]);

void	stdin_to_pipe(int pipe_fds[2]);
void	pipe_to_stdin(int pipe_fds[2]);

void	stdout_to_pipe(int pipe_fds[2]);
void	pipe_to_stdout(int pipe_fds[2]);

void	file_to_stdin(int infile_fd);
void	stdout_to_file(int outfile_fd);

void	str_to_pipe(int pipe_fds[2], char *str);

/******************************************************************************\
 * CLEANUP
\******************************************************************************/

void	free_memory(t_pipex *ctl);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void	check_argc(int argc);

void	die_if_null(void *ptr);
void	die(void);
void	die2(char *location);
void	die3(char *location, int exit_status);
void	die4(int exit_status);
void	die5(char *location, char *message, int exit_status);
void	die6(t_pipex *ctl, char *location);
void	die_cmd(t_pipex *ctl, char *raw_cmd);

void	print_error(char *location, char *message);

#endif
