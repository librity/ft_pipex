/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 02:00:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize(t_pipex *ctl, int argc, char **argv, char **envp)
{
	initialize_pipex(ctl, argc, argv, envp);
	pipe_or_die(ctl->pipe_fds);
	initialize_environment(ctl);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	check_argc(argc);
	initialize(&ctl, argc, argv, envp);
	handle_left(&ctl);
	handle_right(&ctl);
	return (EXIT_SUCCESS);
}
