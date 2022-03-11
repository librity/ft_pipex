/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 20:50:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	free_lingering(t_pipex *ctl)
{
	ft_free_string_array(ctl->paths);
	ft_free_string_array(ctl->right.split);
}

static void	free_and_die(t_pipex *ctl)
{
	print_error(ctl->right.cmd, ERR_NO_CMD);
	free_lingering(ctl);
	exit(EKEYEXPIRED);
}

char	*find_right_executable_or_die(t_pipex *ctl)
{
	char	*command_executable;

	command_executable = find_executable(ctl->right.cmd, ctl->paths);
	if (command_executable == NULL)
		free_and_die(ctl);
	return (command_executable);
}
