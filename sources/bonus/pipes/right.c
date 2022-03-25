/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:14:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:14:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	redirect_right(t_pipex *ctl)
{
	stdout_to_file(ctl->outfile.fd);
	pipe_to_stdin(ctl->pipe_fds);
	close_pipes_fds(ctl->pipe_fds);
	close_or_die(ctl->outfile.fd);
}
