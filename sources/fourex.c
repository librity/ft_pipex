/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 07:29:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize(t_pipex *ctl, int argc, char **argv, char **envp)
{
	initialize_fourex(ctl, argc, argv, envp);
	pipe_or_die(ctl->pipe_fds);
	initialize_environment(ctl);
}

int	fourex(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	check_argc(argc);
	initialize(&ctl, argc, argv, envp);
	handle_left(&ctl);
	handle_right(&ctl);
	return (EXIT_SUCCESS);
}
