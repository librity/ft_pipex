/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 21:51:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	handle_arguments(t_pipex *ctl, int argc, char **argv)
{
	if (argc != 5)
		help_and_die();
	ctl->infile = argv[1];
	ctl->left_cmd = argv[2];
	ctl->right_cmd = argv[3];
	ctl->outfile = argv[4];
	log_command(ctl);
}
