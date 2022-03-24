/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 19:12:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	initialize_outfile(t_pipex *ctl)
{
	ctl->outfile.path = ctl->argv[4];
	ctl->outfile.fd = create_outfile_or_die(ctl);
}

void	initialize_infile(t_pipex *ctl)
{
	ctl->infile.path = ctl->argv[1];
	ctl->infile.fd = open_infile_or_die(ctl);
}

void	initialize_files(t_pipex *ctl)
{
	initialize_outfile(ctl);
	initialize_infile(ctl);
}
