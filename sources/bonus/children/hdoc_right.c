/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:27:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize(t_pipex *ctl)
{
	initialize_outfile(ctl, ctl->argv[5]);
	initialize_hdoc_right(ctl);
}

static void	redirect_fds(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl->right.in_pipe);
	close_pipes_fds(ctl->right.in_pipe);
	close_or_die(ctl->outfile.fd);
}

void	handle_hdoc_right(t_pipex *ctl)
{
	initialize(ctl);
	redirect_fds(ctl);
	execute_or_die(ctl->right.path, ctl->right.tokens, ctl->envp);
	free_memory(ctl);
}
