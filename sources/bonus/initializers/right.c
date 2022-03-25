/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:03:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	set_tokens(t_pipex *ctl)
{
	ctl->right.tokens = tokenize_or_die(ctl->right.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->right.tokens);
}

void	initialize_right(t_pipex *ctl)
{
	ctl->right.raw = ctl->argv[3];
	command_or_die(ctl, ctl->right.raw);
	set_tokens(ctl);
	ctl->right.cmd = ctl->right.tokens[0];
	ctl->right.path = find_right_executable_or_die(ctl);
	ctl->right.flags = ctl->right.tokens + 1;
	log_command(ctl->right.path, ctl->right.flags);
}
