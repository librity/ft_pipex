/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 17:29:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**split_command_or_die(char *raw_command)
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

	executable = ft_strjoin(path, "/");
	executable = ft_strjoin_free(executable, command);
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

static char	*find_executable_or_die(char *command, char **paths)
{
	char *command_executable;

	command_executable = find_executable(command, paths);
	if (command_executable == NULL)
		die2("NO EXECUTABLE");
	return (command_executable);
}

static void	cleanup(char *command, char **paths, char **split_cmd)
{
	free(command);
	ft_free_string_array(paths);
	ft_free_string_array(split_cmd);
}

static void	execute_command(char *command_executable, char **split_cmd, char **envp)
{
	int execve_return;

	execve_return = execve(command_executable, split_cmd, envp);
	if (execve_return < 0)
		die2(command_executable);
}

static void log_command(char *command_executable, char **flags)
{
	if (VERBOSE)
	{
		ft_printf(" => EXECUTABLE: %s\n", command_executable);
		ft_printf(" => FLAGS:\n");
		ft_putstr_array(flags);
	}
}

static void handle_command(char *command_executable, char **split_cmd, char **envp)
{
	int		fork_pid;

	fork_pid = fork_or_die();
	if (fork_pid != CHILD_PROCESS_ID)
		return ;
	execute_command(command_executable, split_cmd, envp);
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
	split_cmd = split_command_or_die(raw_command);
	command = split_cmd[0];
	flags = split_cmd + 1;

	if (ft_strlen(command) == 0)
		die2("NO COMMAND");

	command_executable = find_executable_or_die(command, paths);
	log_command(command_executable, flags);
	handle_command(command_executable, split_cmd, envp);

	cleanup(command_executable, paths, split_cmd);
	return (EXIT_SUCCESS);
}
