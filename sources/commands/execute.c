/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 21:03:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	execute(char *command_path, char **split_cmd, char **envp)
{
	int	execve_return;

	execve_return = execve(command_path, split_cmd, envp);
	if (execve_return < 0)
		die2(command_path);
}
