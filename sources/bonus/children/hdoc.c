/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 01:16:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	get_hdoc_stream(t_pipex *ctl, int pipe[2])
{
	int		status;
	char	*line;

	while (true)
	{
		ft_putstr(HDOC_FEED);
		status = ft_get_next_line(STDIN_FILENO, &line);
		if (status == GNL_ERROR)
			die2(ERR_GNL);
		if (ft_streq(line, ctl->limiter))
		{
			free(line);
			free_memory(ctl);
			exit(EXIT_SUCCESS);
		}
		line = ft_strjoin_free(line, "\n");
		str_to_pipe(pipe, line);
		free(line);
	}
}

void	get_hdoc(t_pipex *ctl)
{
	pid_t	hdoc;
	int		pipe[2];

	pipe_or_die(pipe);
	hdoc = fork_or_die();
	if (hdoc != CHILD_PROCESS_ID)
	{
		get_hdoc_stream(ctl, pipe);
		return ;
	}
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	wait(NULL);
}
