/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 00:07:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize_pipes(t_pipex *ctl)
{
	pipe_or_die(ctl->hdoc.in_pipe);
	pipe_or_die(ctl->left.in_pipe);
	pipe_or_die(ctl->right.in_pipe);
	ctl->left.out_pipe = ctl->right.in_pipe;
}

void	initialize_hdoc(t_pipex *ctl, int argc, char **argv, char **envp)
{
	ctl->argc = argc;
	ctl->argv = argv;
	ctl->envp = envp;
	ctl->free_me = NULL;
	ctl->limiter = ctl->argv[2];
	initialize_pipes(ctl);
	initialize_environment(ctl);
}
