/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 18:55:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	stdin_to_pipe(int pipe_fds[2])
{
	dup2(pipe_fds[PIPE_WRITE], STDIN_FILENO);
}
