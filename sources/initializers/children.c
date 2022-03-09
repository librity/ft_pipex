/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 20:17:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize_child(t_pipex *ctl, t_child *child, char *raw_command)
{
	child->raw = raw_command;
	child->split = split_command_or_die(child->raw);
	child->cmd = child->split[0];
	if (ft_strlen(child->cmd) == 0)
		die2(ERR_NO_CMD);
	child->flags = child->split + 1;
	child->path = find_executable_or_die(child->cmd, ctl->paths);
	log_command(child->path, child->flags);
}

static void	initialize_left(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, &(ctl->left), argv[2]);
}

static void	initialize_right(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, &(ctl->right), argv[3]);
}

void	initialize_children(t_pipex *ctl, char **argv)
{
	initialize_left(ctl, argv);
	initialize_right(ctl, argv);
}
