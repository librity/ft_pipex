/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 20:12:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	run_left(t_pipex *ctl)
{
	stdout_to_pipe(ctl);
	close_pipes_fds(ctl);
	execute_no_args(ctl->left_cmd);
}

void	handle_left(t_pipex *ctl)
{
	ctl->left_pid = fork_or_die();
	if (ctl->left_pid == CHILD_PROCESS_ID)
		run_left(ctl);
}
