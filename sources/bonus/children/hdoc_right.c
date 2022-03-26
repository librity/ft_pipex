/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 00:14:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize(t_pipex *ctl)
{
	ctl->outfile.path = ctl->argv[5];
	ctl->outfile.fd = open_outfile_or_die(ctl);
}

static void	redirect_fds(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl->right.in_pipe);
	close_pipe(ctl->right.in_pipe);
	close_or_die(ctl->outfile.fd);
}

void	handle_hdoc_right(t_pipex *ctl)
{
	initialize(ctl);
	redirect_fds(ctl);
	execute_or_die(ctl, ctl->argv[4]);
	free_memory(ctl);
}
