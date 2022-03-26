/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:47:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 13:53:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	str_to_pipe(int pipe_fds[2], char *str)
{
	write(pipe_fds[PIPE_WRITE], str, ft_strlen(str));
}
