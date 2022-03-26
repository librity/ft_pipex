/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:01:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/26 01:02:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	initialize_control(t_pipex *ctl, int argc, char **argv, char **envp)
{
	ctl->argc = argc;
	ctl->argv = argv;
	ctl->envp = envp;
	ctl->last_cmd = ctl->argv[ctl->argc - 2];
	ctl->paths = NULL;
	ctl->free_me = NULL;
}
