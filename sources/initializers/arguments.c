/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 21:15:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize_left(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, ctl->left, argv[2]);
}

static void	initialize_right(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, ctl->right, argv[3]);
}

void	initialize_arguments(t_pipex *ctl, int argc, char **argv)
{
	if (argc != 5)
		help_and_die();
	ctl->infile = argv[1];
	ctl->outfile = argv[4];
	initialize_left(ctl, argv);
	initialize_right(ctl, argv);
	log_pipex(ctl);
}
