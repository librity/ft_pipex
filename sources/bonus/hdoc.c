/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 14:22:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	hdoc(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	initialize_hdoc(&ctl, argc, argv, envp);
	handle_hdoc_left(&ctl);
	handle_hdoc_right(&ctl);
	return (EXIT_SUCCESS);
}
