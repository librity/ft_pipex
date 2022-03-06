/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 19:54:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	initialize_pipex(t_pipex *ctl, t_child *left, t_child *right)
{
	ctl->left = left;
	ctl->right = right;
}
