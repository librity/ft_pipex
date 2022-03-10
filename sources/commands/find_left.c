/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 19:32:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	free_lingering(t_pipex *ctl)
{
	ft_free_string_array(ctl->paths);
	ft_free_string_array(ctl->right.split);
	ft_free_string_array(ctl->left.split);
	free(ctl->right.path);
}

static void	free_and_die(t_pipex *ctl)
{
	ft_printf("\033[0;31m%s: %s", ctl->left.cmd, ERR_NO_CMD);
	ft_putstr_fd(EXIT_SUCCESS_STR, ctl->outfile.fd);
	free_lingering(ctl);
	exit(EXIT_SUCCESS);
}

char	*find_left_executable_or_die(t_pipex *ctl)
{
	char	*command_executable;

	command_executable = find_executable(ctl->left.cmd, ctl->paths);
	if (command_executable == NULL)
		free_and_die(ctl);
	return (command_executable);
}
