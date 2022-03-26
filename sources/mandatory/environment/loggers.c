/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:24:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	log_path(t_pipex *ctl)
{
	if (VERBOSE)
		ft_printf(" => PATH: \"%s\"\n", ctl->path);
}

void	log_paths(t_pipex *ctl)
{
	if (VERBOSE)
	{
		ft_printf(" => PATHS:\n");
		ft_putstr_array(ctl->paths);
		ft_printf("	TOTAL: %d\n", ft_arrlen((void **)ctl->paths));
	}
}
