/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 15:05:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	fourex(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	check_argc(argc);
	initialize_fourex(&ctl, argc, argv, envp);
	handle_left(&ctl);
	handle_right(&ctl);
	return (EXIT_SUCCESS);
}
