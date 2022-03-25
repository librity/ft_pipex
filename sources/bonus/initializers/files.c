/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:56:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:28:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	initialize_outfile(t_pipex *ctl, char *file_path)
{
	ctl->outfile.path = file_path;
	ctl->outfile.fd = create_outfile_or_die(ctl);
}

void	initialize_infile(t_pipex *ctl, char *file_path)
{
	ctl->infile.path = file_path;
	ctl->infile.fd = open_infile_or_die(ctl);
}

