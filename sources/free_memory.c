/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 15:44:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	free_left(t_pipex *ctl)
{
	free(ctl->left.path);
	ft_free_string_array(ctl->left.split);
}

static void	free_right(t_pipex *ctl)
{
	free(ctl->right.path);
	ft_free_string_array(ctl->right.split);
}

void	free_memory(t_pipex *ctl)
{
	ft_free_string_array(ctl->paths);
	free_left(ctl);
	free_right(ctl);
}
