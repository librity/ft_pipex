/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 22:10:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	initialize_hdoc(t_pipex *ctl, int argc, char **argv, char **envp)
{
	ctl->argc = argc;
	ctl->argv = argv;
	ctl->envp = envp;
	ctl->free_me = NULL;
	pipe_or_die(ctl->pipe_fds);
	initialize_environment(ctl);
}
