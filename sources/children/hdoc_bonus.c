/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 18:55:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// static void	redirect_descriptors(t_pipex *ctl)
// {
// 	file_to_stdin(ctl->infile.fd);
// 	stdout_to_pipe(ctl->pipe_fds);
// 	close_pipes_fds(ctl->pipe_fds);
// 	close_or_die(ctl->infile.fd);
// }

// static void	initialize(t_pipex *ctl)
// {
// 	initialize_hdoc(ctl);
// 	initialize_infile(ctl);
// }

void	handle_hdoc(t_pipex *ctl)
{
	ctl->hdoc.pid = fork_or_die();
	if (ctl->hdoc.pid != CHILD_PROCESS_ID)
		return ;
	// initialize(ctl);
	// redirect_descriptors(ctl);
	// execute_or_die(ctl->hdoc.path, ctl->hdoc.tokens, ctl->envp);
	// free_memory(ctl);
}
