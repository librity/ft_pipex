/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 17:56:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	create_outfile_or_die(t_pipex *ctl)
{
	int	open_fd;
	int	flags;

	flags = O_CREAT | O_WRONLY | O_TRUNC;
	open_fd = open(ctl->outfile.path, flags, CREATE_PERMISSION);
	if (open_fd < 0)
	{
		free_memory(ctl);
		die2(ctl->outfile.path);
	}
	return (open_fd);
}

int	open_outfile_or_die(t_pipex *ctl)
{
	int	open_fd;
	int	flags;

	flags = O_CREAT | O_WRONLY | O_APPEND;
	open_fd = open(ctl->outfile.path, flags, CREATE_PERMISSION);
	if (open_fd < 0)
	{
		free_memory(ctl);
		die2(ctl->outfile.path);
	}
	return (open_fd);
}
