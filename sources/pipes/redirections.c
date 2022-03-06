/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 22:00:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	stdout_to_pipe(t_pipex *ctl)
{
	dup2(ctl->pipe_fds[1], STDOUT_FILENO);
}

void	pipe_to_stdin(t_pipex *ctl)
{
	dup2(ctl->pipe_fds[0], STDIN_FILENO);
}

void	file_to_stdin(int infile_fd)
{
	dup2(infile_fd, STDIN_FILENO);
}

void	stdout_to_file(int outfile_fd)
{
	dup2(outfile_fd, STDOUT_FILENO);
}
