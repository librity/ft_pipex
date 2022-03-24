/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 00:54:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl->pipe_fds);
	close_pipes_fds(ctl->pipe_fds);
}

void	handle_right(t_pipex *ctl)
{
	initialize_outfile(ctl, ctl->argv);
	initialize_right(ctl, ctl->argv);
	redirect_descriptors(ctl);
	close_or_die(ctl->outfile.fd);
	execute_or_die(ctl->right.path, ctl->right.tokens, ctl->envp);
}
