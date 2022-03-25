/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:16:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	set_tokens(t_pipex *ctl)
{
	ctl->hdoc.tokens = tokenize_or_die(ctl->hdoc.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->hdoc.tokens);
}

void	initialize_hdoc_hdoc(t_pipex *ctl)
{
	ctl->hdoc.limiter = ctl->argv[2];
	ctl->hdoc.raw = ctl->argv[3];
	command_or_die(ctl, ctl->hdoc.raw);
	set_tokens(ctl);
	ctl->hdoc.cmd = ctl->hdoc.tokens[0];
	ctl->hdoc.path = find_hdoc_executable_or_die(ctl);
	ctl->hdoc.flags = ctl->hdoc.tokens + 1;
	log_command(ctl->hdoc.path, ctl->hdoc.flags);
}
