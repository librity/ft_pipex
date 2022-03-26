/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 22:56:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	redirect_fds(t_pipex *ctl)
{
	stdout_to_pipe(ctl->left.out_pipe);
	close_pipe(ctl->left.out_pipe);
}

void	handle_hdoc_left(t_pipex *ctl)
{
	ctl->left.pid = fork_or_die();
	if (ctl->left.pid != CHILD_PROCESS_ID)
		return ;
	initialize_hdoc_left(ctl);
	redirect_fds(ctl);
	execute_or_die(ctl->left.path, ctl->left.tokens, ctl->envp);
	free_memory(ctl);
}
