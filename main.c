/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 17:04:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	handle_arguments(&ctl, argc, argv);
	handle_environment(&ctl, envp);
	pipe_or_die(&ctl);
	handle_left(&ctl);
	handle_right(&ctl);
	close_pipes_fds(&ctl);
	wait_for_children(&ctl);
	cleanup(&ctl);
	return (EXIT_SUCCESS);
}
