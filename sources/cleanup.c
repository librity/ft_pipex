/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 21:36:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	cleanup_left(t_pipex *ctl)
{
	free(ctl->left->path);
	ft_free_string_array(ctl->left->split);
}

static void	cleanup_right(t_pipex *ctl)
{
	free(ctl->right->path);
	ft_free_string_array(ctl->right->split);
}

void	cleanup(t_pipex *ctl)
{
	ft_free_string_array(ctl->paths);
	cleanup_left(ctl);
	cleanup_right(ctl);
}
