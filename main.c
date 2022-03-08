/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 15:53:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize(t_pipex *ctl, int argc, char **argv, char **envp)
{
	initialize_environment(ctl, envp);
	initialize_arguments(ctl, argc, argv);
	pipe_or_die(ctl);
}

static void	handle_children(t_pipex *ctl)
{
	handle_left(ctl);
	handle_right(ctl);
	close_pipes_fds(ctl);
	wait_for_children(ctl);
}

static void	cleanup(t_pipex *ctl)
{
	free_memory(ctl);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	initialize(&ctl, argc, argv, envp);
	handle_children(&ctl);
	cleanup(&ctl);
	return (EXIT_SUCCESS);
}
