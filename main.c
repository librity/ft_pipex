/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/12 00:44:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// static void	initialize(t_pipex *ctl, char **argv, char **envp)
// {
// 	initialize_pipex(ctl);
// 	initialize_files(ctl, argv);
// 	initialize_environment(ctl, envp);
// 	initialize_children(ctl, argv);
// 	pipe_or_die(ctl);
// 	log_pipex(ctl);
// }

// static void	handle_children(t_pipex *ctl)
// {
// 	handle_left(ctl);
// 	handle_right(ctl);
// 	close_pipes_fds(ctl);
// 	wait_for_children(ctl);
// }

static void	cleanup(t_pipex *ctl)
{
	free_memory(ctl);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	check_argc(argc);

	// initialize(&ctl, argv, envp);
	initialize_pipex(&ctl);
	initialize_files(&ctl, argv);
	initialize_environment(&ctl, envp);
	initialize_children(&ctl, argv);
	pipe_or_die(ctl.pipe_fds);
	log_pipex(&ctl);

	// handle_children(&ctl);
	handle_left(&ctl);
	handle_right(&ctl);
	close_pipes_fds(ctl.pipe_fds);
	wait_for_children(&ctl);

	cleanup(&ctl);
	return (EXIT_SUCCESS);
}
