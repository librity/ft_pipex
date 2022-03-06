/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 22:14:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipe_or_die(t_pipex *ctl)
{
	int	pipe_return;

	pipe_return = pipe(ctl->pipe_fds);
	if (pipe_return < 0)
		die();
}

void	close_pipes_fds(t_pipex *ctl)
{
	close_or_die(ctl->pipe_fds[0]);
	close_or_die(ctl->pipe_fds[1]);
}
