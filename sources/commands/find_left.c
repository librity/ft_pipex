/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 02:06:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// static void	free_and_die(t_pipex *ctl)
// {
// 	print_error(ctl->left.cmd, ERR_NO_CMD);
// 	ft_putstr_fd(EXIT_SUCCESS_STR, ctl->outfile.fd);
// 	free_memory(ctl);
// 	exit(EXIT_SUCCESS);
// }

char	*find_left_executable_or_die(t_pipex *ctl)
{
	char	*command_executable;

	command_executable = find_executable(ctl->left.cmd, ctl->paths);
	if (command_executable == NULL)
		die_cmd(ctl, ctl->left.cmd);
		// free_and_die(ctl);
	ft_add_lalloc(&ctl->free_me, command_executable);
	return (command_executable);
}
