/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 01:03:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize_files(t_pipex *ctl)
{
	ctl->outfile.path = ctl->argv[ctl->argc - 1];
	ctl->outfile.fd = open_outfile_or_die(ctl);
}

void	initialize_hdoc(t_pipex *ctl)
{
	ctl->arg = 3;
	ctl->limiter = ctl->argv[2];
	initialize_files(ctl);
	get_hdoc(ctl);
}
