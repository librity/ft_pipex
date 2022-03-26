/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hdoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 00:04:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	get_hdoc_stream(t_pipex *ctl)
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
			exit(EXIT_SUCCESS);
		}
		line = ft_strjoin_free(line, "\n");
		str_to_pipe(ctl->hdoc.in_pipe, line);
		free(line);
	}
}

void	handle_hdoc(t_pipex *ctl)
{
	ctl->hdoc.pid = fork_or_die();
	if (ctl->hdoc.pid != CHILD_PROCESS_ID)
	{
		get_hdoc_stream(ctl);
		return ;
	}
	pipe_to_stdin(ctl->hdoc.in_pipe);
	close_pipe(ctl->hdoc.in_pipe);
	wait(NULL);
}
