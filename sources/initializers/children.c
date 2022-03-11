/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 21:15:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize_right(t_pipex *ctl, char **argv)
{
	ctl->right.raw = argv[3];
	ctl->right.split = tokenize_or_die(ctl->right.raw);
	ctl->right.cmd = ctl->right.split[0];
	ctl->right.path = find_right_executable_or_die(ctl);
	ctl->right.flags = ctl->right.split + 1;
	log_command(ctl->right.path, ctl->right.flags);
}

static void	initialize_left(t_pipex *ctl, char **argv)
{
	ctl->left.raw = argv[2];
	ctl->left.split = tokenize_or_die(ctl->left.raw);
	ctl->left.cmd = ctl->left.split[0];
	ctl->left.path = find_left_executable_or_die(ctl);
	ctl->left.flags = ctl->left.split + 1;
	log_command(ctl->left.path, ctl->left.flags);
}

void	initialize_children(t_pipex *ctl, char **argv)
{
	initialize_right(ctl, argv);
	initialize_left(ctl, argv);
}
