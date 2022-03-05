/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/03 08:35:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	redirect_descriptors(t_pipex *ctl)
{
	ctl->outfile_fd = create_file_or_die(ctl->outfile);
	stdout_to_file(ctl->outfile_fd);
	pipe_to_stdin(ctl);
	close_pipes_fds(ctl);
}

void	handle_right(t_pipex *ctl)
{
	ctl->right_pid = fork_or_die();
	if (ctl->right_pid != CHILD_PROCESS_ID)
		return ;
	redirect_descriptors(ctl);
	close_or_die(ctl->outfile_fd);
	execute_no_args(ctl->right_cmd);
}
