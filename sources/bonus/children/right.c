/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:28:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	redirect_fds(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl->pipe);
	close_pipes_fds(ctl->pipe);
	close_or_die(ctl->outfile.fd);
}

static void	initialize(t_pipex *ctl)
{
	initialize_outfile(ctl, ctl->argv[4]);
	initialize_right(ctl);
}

void	handle_right(t_pipex *ctl)
{
	initialize(ctl);
	redirect_fds(ctl);
	execute_or_die(ctl->right.path, ctl->right.tokens, ctl->envp);
	free_memory(ctl);
}
