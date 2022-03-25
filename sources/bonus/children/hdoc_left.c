/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:13:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	stdout_to_pipe(ctl->pipe_fds);
	close_pipes_fds(ctl->pipe_fds);
}

void	handle_hdoc_left(t_pipex *ctl)
{
	ctl->hdoc.pid = fork_or_die();
	if (ctl->hdoc.pid != CHILD_PROCESS_ID)
		return ;
	initialize_hdoc_child(ctl);
	redirect_descriptors(ctl);
	execute_or_die(ctl->hdoc.path, ctl->hdoc.tokens, ctl->envp);
	free_memory(ctl);
}
