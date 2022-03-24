/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 02:08:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	set_left_split(t_pipex *ctl)
{
	ctl->left.tokens = tokenize_or_die(ctl->left.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->left.tokens);
}

void	initialize_left(t_pipex *ctl)
{
	ctl->left.raw = ctl->argv[2];
	command_or_die(ctl, ctl->left.raw);
	set_left_split(ctl);
	ctl->left.cmd = ctl->left.tokens[0];
	ctl->left.path = find_left_executable_or_die(ctl);
	ctl->left.flags = ctl->left.tokens + 1;
	log_command(ctl->left.path, ctl->left.flags);
}
