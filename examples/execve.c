/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 22:54:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	static_cleanup(char *command, char **paths, char **split_cmd)
{
	free(command);
	ft_free_string_array(paths);
	ft_free_string_array(split_cmd);
}

static void handle_command(char *command_executable, char **split_cmd, char **envp)
{
	int		fork_pid;

	fork_pid = fork_or_die();
	if (fork_pid != CHILD_PROCESS_ID)
		return ;
	execute_or_die(command_executable, split_cmd, envp);
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

	static_cleanup(command_executable, paths, split_cmd);
	return (EXIT_SUCCESS);
}
