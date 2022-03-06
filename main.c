/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 20:10:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ctl;
	t_child	left;
	t_child	right;

	initialize((t_initialize){argc, argv, envp, &ctl, &left, &right});
	pipe_or_die(&ctl);
	handle_left(&ctl);
	handle_right(&ctl);
	close_pipes_fds(&ctl);
	wait_for_children(&ctl);
	cleanup(&ctl);
	return (EXIT_SUCCESS);
}
