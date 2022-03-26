/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 23:56:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize_execute(t_pipex *ctl, char *raw_cmd, t_exec *ex)
{
	command_or_die(ctl, raw_cmd);
	ex->tokens = tokenize_or_die(raw_cmd);
	ft_add_lalloc_array(&ctl->free_me, (void **)ex->tokens);
	ex->cmd = ex->tokens[0];
	ex->path = find_executable(ex->cmd, ctl->paths);
	if (ex->path == NULL)
		die_cmd(ctl, ex->cmd);
	ft_add_lalloc(&ctl->free_me, ex->path);
}

void	execute_or_die(t_pipex *ctl, char *raw_cmd)
{
	t_exec	ex;

	initialize_execute(ctl, raw_cmd, &ex);
	ex.code = execve(ex.path, ex.tokens, ctl->envp);
	if (ex.code < 0)
		die6(ctl, ex.path);
}
