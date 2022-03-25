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

typedef struct s_child
{
	int		pid;

	char	*raw;
	char	**tokens;
	char	*cmd;
	char	**flags;
	char	*path;

	char	*limiter;

	int		in_pipe[2];
	int		*out_pipe;
}		t_child;

typedef struct s_pipex
{
	int		argc;
	char	**argv;

	char	**envp;
	char	*path;
	char	**paths;

	int		pipe[2];

	int		pipes_count;
	t_list	*pipes;

	t_file	infile;
	t_child	left;

	t_child	right;
	t_file	outfile;

	int		children_count;
	t_list	*children;

	t_list	*free_me;
}		t_pipex;

int		fourex(int argc, char **argv, char **envp);
int		nex(int argc, char **argv, char **envp);
int		hdoc(int argc, char **argv, char **envp);

void	initialize_fourex(t_pipex *ctl, int argc, char **argv, char **envp);
void	initialize_hdoc(t_pipex *ctl, int argc, char **argv, char **envp);
void	initialize_nex(t_pipex *ctl, int argc, char **argv, char **envp);

void	initialize_environment(t_pipex *ctl);

void	initialize_right(t_pipex *ctl);
void	initialize_left(t_pipex *ctl);

void	initialize_hdoc_left(t_pipex *ctl);
void	initialize_hdoc_right(t_pipex *ctl);

void	initialize_outfile(t_pipex *ctl, char *file_path);
void	initialize_infile(t_pipex *ctl, char *file_path);

void	command_or_die(t_pipex *ctl, char *raw_cmd);

char	*get_clean_path_or_die(char **envp);
char	**get_paths_or_die(char **envp);

void	log_fourex(t_pipex *ctl);
void	log_path(t_pipex *ctl);
void	log_paths(t_pipex *ctl);
void	log_command(char *command_executable, char **flags);
void	log_hdoc(t_pipex *ctl);

int		create_file_or_die(char *path);
int		open_file_or_die(char *path);
int		close_or_die(int close_me);

int		open_infile_or_die(t_pipex *ctl);
int		create_outfile_or_die(t_pipex *ctl);

void	pipe_or_die(int pipe_fds[2]);
void	close_pipes_fds(int pipe_fds[2]);

void	stdin_to_pipe(int pipe_fds[2]);
void	pipe_to_stdin(int pipe_fds[2]);

void	stdout_to_pipe(int pipe_fds[2]);

void	file_to_stdin(int infile_fd);
void	stdout_to_file(int outfile_fd);

void	str_to_pipe(int pipe_fds[2], char *str);

int		fork_or_die(void);
void	wait_for_left(t_pipex *ctl);
void	wait_for_right(t_pipex *ctl);
void	wait_for_children(t_pipex *ctl);

char	*find_executable(char *command, char **paths);
char	*find_executable_or_die(char *command, char **paths);
char	**split_command_or_die(char *raw_command);
char	**tokenize_or_die(char *raw_command);
void	execute_or_die(char *command_path, char **split_cmd, char **envp);

void	set_child_executable_or_die(t_pipex *ctl, t_child *child);

void	handle_left(t_pipex *ctl);
void	handle_right(t_pipex *ctl);

void	handle_hdoc_left(t_pipex *ctl);
void	handle_hdoc_right(t_pipex *ctl);

void	free_memory(t_pipex *ctl);

void	check_argc(int argc);

void	die_if_null(void *ptr);
void	die(void);
void	die2(char *location);
void	die3(char *location, int exit_status);
void	die4(int exit_status);
void	die5(char *location, char *message, int exit_status);
void	die_cmd(t_pipex *ctl, char *raw_cmd);

void	print_error(char *location, char *message);

#endif
