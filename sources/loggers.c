/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 20:02:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	log_command(t_pipex *ctl)
{
	if (VERBOSE)
		ft_printf(
			" => Executing \"< %s %s | %s > %s\"\n",
			ctl->infile,
			ctl->left_cmd,
			ctl->right_cmd,
			ctl->outfile);
}

void	log_path(t_pipex *ctl)
{
	if (VERBOSE)
		ft_printf(" => PATH: \"%s\"\n", ctl->path);
}
