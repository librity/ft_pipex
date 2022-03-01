/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 20:12:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	run_right(t_pipex *ctl)
{
	pipe_to_stdin(ctl);
	close_pipes_fds(ctl);
	execute_no_args(ctl->right_cmd);
}

void	handle_right(t_pipex *ctl)
{
	ctl->right_pid = fork_or_die();
	if (ctl->right_pid == CHILD_PROCESS_ID)
		run_right(ctl);
}
