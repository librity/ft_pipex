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
# include <ft_printf.h>
# include <stdio.h>
# include <stdlib.h>
# include <utils.h>

# define CHILD_PROCESS_ID 0

typedef struct s_pipex
{
	int		pipe_fds[2];

	char	*infile;
	int		infile_fd;

	char	*left_cmd;
	char	*right_cmd;

	char	*outfile;
	int		outfile_fd;
}		t_pipex;

void	handle_arguments(t_pipex *ctl, int argc, char **argv);

void	help_and_die(void);
void	die(void);
void	die_if_null(void *ptr);

#endif
