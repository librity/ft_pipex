/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 22:54:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	ctl->infile_fd = open_file_or_die(ctl->infile);
	file_to_stdin(ctl->infile_fd);
	stdout_to_pipe(ctl);
	close_pipes_fds(ctl);
}

void	handle_left(t_pipex *ctl)
{
	ctl->left->pid = fork_or_die();
	if (ctl->left->pid != CHILD_PROCESS_ID)
		return ;
	redirect_descriptors(ctl);
	close_or_die(ctl->infile_fd);
	execute_or_die(ctl->left->path, ctl->left->split, ctl->envp);
}
