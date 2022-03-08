/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 15:45:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize_infile(t_pipex *ctl, char **argv)
{
	ctl->infile.path = argv[1];
	ctl->infile.fd = open_file_or_die(ctl->infile.path);
}

static void	initialize_left(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, &(ctl->left), argv[2]);
}

static void	initialize_right(t_pipex *ctl, char **argv)
{
	initialize_child(ctl, &(ctl->right), argv[3]);
}

static void	initialize_outfile(t_pipex *ctl, char **argv)
{
	ctl->outfile.path = argv[4];
	ctl->outfile.fd = create_file_or_die(ctl->outfile.path);
}

void	initialize_arguments(t_pipex *ctl, int argc, char **argv)
{
	if (argc != 5)
		help_and_die();
	initialize_infile(ctl, argv);
	initialize_left(ctl, argv);
	initialize_right(ctl, argv);
	initialize_outfile(ctl, argv);
	log_pipex(ctl);
}
