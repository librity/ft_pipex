/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 18:55:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	hdoc(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	initialize_hdoc(&ctl, argc, argv, envp);
	// handle_hdoc(&ctl);
	// handle_right(&ctl);
	return (EXIT_SUCCESS);
}
