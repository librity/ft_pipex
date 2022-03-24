/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 16:53:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	set_paths(t_pipex *ctl)
{
	ctl->paths = get_paths_or_die(ctl->envp);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->paths);
}

void	initialize_environment(t_pipex *ctl)
{
	ctl->path = get_clean_path_or_die(ctl->envp);
	set_paths(ctl);
	log_path(ctl);
	log_paths(ctl);
}
