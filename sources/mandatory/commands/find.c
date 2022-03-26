/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 18:43:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*build_executable_path(char *path, char *command)
{
	char	*executable;

	executable = ft_strjoin(path, "/");
	executable = ft_strjoin_free(executable, command);
	return (executable);
}

char	*find_executable(char *command, char **paths)
{
	char	*executable;
	int		can_execute;

	while (*paths)
	{
		executable = build_executable_path(*paths, command);
		can_execute = access(executable, X_OK);
		if (can_execute == 0)
			return (executable);
		free(executable);
		paths++;
	}
	return (NULL);
}

char	*find_executable_or_die(char *command, char **paths)
{
	char	*command_executable;

	command_executable = find_executable(command, paths);
	if (command_executable == NULL)
		die5(command, "command not found", EXIT_FAILURE);
	return (command_executable);
}
