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

#ifndef PIPEX_H
# define PIPEX_H

# include <defines.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <stdio.h>
# include <sys/wait.h>
# include <utils.h>

typedef struct s_file
{
	char	*path;
	int		fd;
}		t_file;

typedef struct s_child
{
	int		pid;

	char	*raw;
	char	**split;
	char	*cmd;
	char	**flags;
	char	*path;
}		t_child;

typedef struct s_pipex
{
	char	**envp;
	char	*path;
	char	**paths;

	int		pipe_fds[2];

	t_file	infile;
	t_child	left;

	t_child	right;
	t_file	outfile;
}		t_pipex;

void	initialize_files(t_pipex *ctl, char **argv);
void	initialize_environment(t_pipex *ctl, char **envp);
void	initialize_children(t_pipex *ctl, char **argv);

char	*get_clean_path_or_die(char **envp);
char	**get_paths_or_die(char **envp);

void	log_pipex(t_pipex *ctl);
void	log_path(t_pipex *ctl);
void	log_paths(t_pipex *ctl);
void	log_command(char *command_executable, char **flags);

int		create_file_or_die(char *path);
int		open_file_or_die(char *path);
int		close_or_die(int close_me);

void	pipe_or_die(t_pipex *ctl);
void	close_pipes_fds(t_pipex *ctl);

void	stdout_to_pipe(t_pipex *ctl);
void	pipe_to_stdin(t_pipex *ctl);
void	file_to_stdin(int infile_fd);
void	stdout_to_file(int outfile_fd);

int		fork_or_die(void);
void	wait_for_children(t_pipex *ctl);

char	*find_executable(char *command, char **paths);
char	*find_executable_or_die(char *command, char **paths);
char	*find_right_executable_or_die(char *command, char **paths);
char	*find_left_executable_or_die(char *command, char **paths);

char	**split_command_or_die(char *raw_command);
void	execute_or_die(char *command_path, char **split_cmd, char **envp);

void	handle_left(t_pipex *ctl);
void	handle_right(t_pipex *ctl);

void	free_memory(t_pipex *ctl);

void	help_and_die(void);
void	check_argc(int argc);

void	die_if_null(void *ptr);
void	die(void);
void	die2(char *location);
void	die3(char *location, int exit_status);
void	die4(int exit_status);
void	die5(char *location, char *message, int exit_status);

#endif
