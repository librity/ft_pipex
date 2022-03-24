/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nex_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 06:33:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 18:55:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	nex(int argc, char **argv, char **envp)
{
	t_pipex	ctl;

	initialize_nex(&ctl, argc, argv, envp);
	return (EXIT_SUCCESS);
}
