/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 15:48:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl);
	close_pipes_fds(ctl);
}

void	handle_right(t_pipex *ctl)
{
	ctl->right.pid = fork_or_die();
	if (ctl->right.pid != CHILD_PROCESS_ID)
		return ;
	redirect_descriptors(ctl);
	close_or_die(ctl->outfile.fd);
	execute_or_die(ctl->right.path, ctl->right.split, ctl->envp);
}
