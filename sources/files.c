/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 00:34:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	create_file_or_die(char *filename)
{
	int	open_fd;
	int	create_flags;

	create_flags = O_CREAT | O_WRONLY | O_TRUNC;
	open_fd = open(filename, create_flags, CREATE_PERMISSION);
	if (open_fd < 0)
		die_indicated(filename);
	return (open_fd);
}

int	open_file_or_die(char *filename)
{
	int	open_fd;
	int	open_flags;

	open_flags = O_RDONLY;
	open_fd = open(filename, open_flags);
	if (open_fd < 0)
		die_indicated(filename);
	return (open_fd);
}

int	close_or_die(int close_fd)
{
	close_fd = close(close_fd);
	if (close_fd < 0)
		die();
	return (close_fd);
}
