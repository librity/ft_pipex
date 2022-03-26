/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 02:05:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*find_right_executable_or_die(t_pipex *ctl)
{
	char	*command_executable;

	command_executable = find_executable(ctl->right.cmd, ctl->paths);
	if (command_executable == NULL)
		die_cmd(ctl, ctl->right.cmd);
	ft_add_lalloc(&ctl->free_me, command_executable);
	return (command_executable);
}
