/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:29:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/05 20:12:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	fork_or_die(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		die();
	return (pid);
}

void	wait_for_children(t_pipex *ctl)
{
	waitpid(ctl->left->pid, NULL, 0);
	waitpid(ctl->right->pid, NULL, 0);
}
