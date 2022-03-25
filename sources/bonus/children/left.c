/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:29:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	file_to_stdin(ctl->infile.fd);
	stdout_to_pipe(ctl->pipe);
	close_pipes_fds(ctl->pipe);
	close_or_die(ctl->infile.fd);
}

static void	initialize(t_pipex *ctl)
{
	initialize_left(ctl);
	initialize_infile(ctl, ctl->argv[1]);
}

void	handle_left(t_pipex *ctl)
{
	ctl->left.pid = fork_or_die();
	if (ctl->left.pid != CHILD_PROCESS_ID)
		return ;
	initialize(ctl);
	redirect_descriptors(ctl);
	execute_or_die(ctl->left.path, ctl->left.tokens, ctl->envp);
	free_memory(ctl);
}
