/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 01:21:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	create_file_or_die(char *path)
{
	int	open_fd;
	int	create_flags;

	create_flags = O_CREAT | O_WRONLY | O_TRUNC;
	open_fd = open(path, create_flags, CREATE_PERMISSION);
	if (open_fd < 0)
		die2(path);
	return (open_fd);
}
