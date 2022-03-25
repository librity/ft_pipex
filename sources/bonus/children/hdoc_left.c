/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:36:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	get_hdoc(t_pipex *ctl)
{
	int		status;
	char	*line;

	while (true)
	{
		ft_putstr(HDOC_FEED);
		status = ft_gnl(STDIN_FILENO, &line);
		if (status == GNL_ERROR)
			die2(ERR_GNL);
		if (ft_streq(line, ctl->left.limiter))
		{
			free(line);
			break ;
		}
		str_to_pipe(ctl->left.in_pipe, line);
		free(line);
	}
}

static void	redirect_fds(t_pipex *ctl)
{
	pipe_to_stdin(ctl->left.in_pipe);
	stdout_to_pipe(ctl->left.out_pipe);
	close_pipes_fds(ctl->left.in_pipe);
	close_pipes_fds(ctl->left.out_pipe);
}

void	handle_hdoc_left(t_pipex *ctl)
{
	ctl->left.pid = fork_or_die();
	if (ctl->left.pid != CHILD_PROCESS_ID)
		return ;
	initialize_hdoc_left(ctl);
	get_hdoc(ctl);
	redirect_fds(ctl);
	execute_or_die(ctl->left.path, ctl->left.tokens, ctl->envp);
	free_memory(ctl);
}
