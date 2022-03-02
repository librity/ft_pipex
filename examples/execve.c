/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 20:14:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**split_command(char *raw_command)
{
	char	**split_command;

	split_command = ft_split(raw_command, ' ');
	if (split_command == NULL)
		die();
	return (split_command);
}

static char	*build_executable_path(char *path, char *command)
{
	char	*executable;
	char	*free_me;

	free_me = ft_strjoin(path, "/");
	executable = ft_strjoin(free_me, command);
	free(free_me);
	return (executable);
}

static char	*find_executable(char *command, char **paths)
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

static void	cleanup(char *command, char **paths, char **split_cmd)
{
	free(command);
	ft_free_string_array(paths);
	ft_free_string_array(split_cmd);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*raw_command;
	char	**split_cmd;
	char	**flags;
	char	*command;
	char	*command_executable;

	raw_command = "ls -l -a -s";
	paths = get_paths_or_die(envp);
	split_cmd = split_command(raw_command);
	command = split_cmd[0];
	flags = split_cmd + 1;

	if (ft_strlen(command) == 0)
		die_indicated("NO COMMAND");

	command_executable = find_executable(command, paths);
	if (command_executable == NULL)
		die_indicated("NO EXECUTABLE");

	ft_printf("	=> EXECUTING: %s with flags:\n", command_executable);
	ft_putstr_array(flags);
	if (execve(command_executable, split_cmd, envp) == -1)
		die_indicated("execve");

	cleanup(command_executable, paths, split_cmd);
	return (EXIT_SUCCESS);
}
