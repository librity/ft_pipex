/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 18:15:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	set_paths(t_pipex *ctl, char **envp)
{
	ctl->paths = get_paths_or_die(envp);
	ft_add_lalloc_array(&ctl->free_me, (void **)ctl->paths);
}

void	initialize_environment(t_pipex *ctl, char **envp)
{
	ctl->envp = envp;
	ctl->path = get_clean_path_or_die(envp);
	set_paths(ctl, envp);
	log_path(ctl);
	log_paths(ctl);
}
