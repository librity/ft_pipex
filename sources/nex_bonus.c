/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nex_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 07:40:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	initialize(t_pipex *ctl, int argc, char **argv, char **envp)
{
	initialize_nex(ctl, argc, argv, envp);
}

int	nex(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	check_argc_nex(argc);
	initialize(&ctl, argc, argv, envp);
	return (EXIT_SUCCESS);
}
