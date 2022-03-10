/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 18:42:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*find_left_executable_or_die(char *command, char **paths)
{
	char	*command_executable;

	command_executable = find_executable(command, paths);
	if (command_executable == NULL)
		die5(command, "command not found", EXIT_SUCCESS);
	return (command_executable);
}
