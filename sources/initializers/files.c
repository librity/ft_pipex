/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 20:17:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	initialize_infile(t_pipex *ctl, char **argv)
{
	ctl->infile.path = argv[1];
	ctl->infile.fd = open_file_or_die(ctl->infile.path);
}

static void	initialize_outfile(t_pipex *ctl, char **argv)
{
	ctl->outfile.path = argv[4];
	ctl->outfile.fd = create_file_or_die(ctl->outfile.path);
}

void	initialize_files(t_pipex *ctl, char **argv)
{
	initialize_infile(ctl, argv);
	initialize_outfile(ctl, argv);
}
