/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 00:38:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	file_to_stdin(ctl->infile.fd);
	stdout_to_pipe(ctl->pipe_fds);
	close_pipes_fds(ctl->pipe_fds);
	close_or_die(ctl->infile.fd);
}

void	handle_left(t_pipex *ctl)
{
	ctl->left.pid = fork_or_die();
	if (ctl->left.pid != CHILD_PROCESS_ID)
		return ;
	initialize_left(ctl, ctl->argv);
	initialize_infile(ctl, ctl->argv);
	redirect_descriptors(ctl);
	execute_or_die(ctl->left.path, ctl->left.tokens, ctl->envp);
}
