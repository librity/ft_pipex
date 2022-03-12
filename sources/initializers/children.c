/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 23:51:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	set_right_split(t_pipex *ctl)
{
	ctl->right.tokens = tokenize_or_die(ctl->right.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->right.tokens);
}

static void	set_left_split(t_pipex *ctl)
{
	ctl->left.tokens = tokenize_or_die(ctl->left.raw);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->left.tokens);
}

void	initialize_right(t_pipex *ctl, char **argv)
{
	ctl->right.raw = argv[3];
	set_right_split(ctl);
	ctl->right.cmd = ctl->right.tokens[0];
	ctl->right.path = find_right_executable_or_die(ctl);
	ctl->right.flags = ctl->right.tokens + 1;
	log_command(ctl->right.path, ctl->right.flags);
}

void	initialize_left(t_pipex *ctl, char **argv)
{
	ctl->left.raw = argv[2];
	set_left_split(ctl);
	ctl->left.cmd = ctl->left.tokens[0];
	ctl->left.path = find_left_executable_or_die(ctl);
	ctl->left.flags = ctl->left.tokens + 1;
	log_command(ctl->left.path, ctl->left.flags);
}

void	initialize_children(t_pipex *ctl, char **argv)
{
	initialize_right(ctl, argv);
	initialize_left(ctl, argv);
}
