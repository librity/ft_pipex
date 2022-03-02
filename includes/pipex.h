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

typedef struct s_pipex
{
	char	**envp;
	char	*path;
	char	**paths;

	int		pipe_fds[2];

	char	*infile;
	int		infile_fd;

	char	*left_cmd;
	int		left_pid;

	char	*right_cmd;
	int		right_pid;

	char	*outfile;
	int		outfile_fd;
}		t_pipex;

void	handle_arguments(t_pipex *ctl, int argc, char **argv);
void	handle_environment(t_pipex *ctl, char **envp);

char	*get_clean_path_or_die(char **envp);
char	**get_paths_or_die(char **envp);

void	log_command(t_pipex *ctl);
void	log_path(t_pipex *ctl);
void	log_paths(t_pipex *ctl);

int		create_file_or_die(char *filename);
int		open_file_or_die(char *filename);
int		close_or_die(int close_fd);

void	pipe_or_die(t_pipex *ctl);
void	close_pipes_fds(t_pipex *ctl);

void	stdout_to_pipe(t_pipex *ctl);
void	pipe_to_stdin(t_pipex *ctl);
void	file_to_stdin(int infile_fd);
void	stdout_to_file(int outfile_fd);

int		fork_or_die(void);
void	wait_for_children(t_pipex *ctl);

void	execute_no_args(char *command);

void	handle_left(t_pipex *ctl);
void	handle_right(t_pipex *ctl);

void	help_and_die(void);
void	die_if_null(void *ptr);
void	die(void);
void	die_indicated(char *indicator);

#endif
