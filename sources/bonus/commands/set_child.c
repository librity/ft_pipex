/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 13:57:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	set_child_executable_or_die(t_pipex *ctl, t_child *child)
{
	char	*command_executable;

	command_executable = find_executable(child->cmd, ctl->paths);
	if (command_executable == NULL)
		die_cmd(ctl, child->cmd);
	child->path = command_executable;
	ft_add_lalloc(&ctl->free_me, command_executable);
}
