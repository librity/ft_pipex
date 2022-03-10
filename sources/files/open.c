/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 18:30:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	exists_or_die(char *path)
{
	int	exists;

	exists = access(path, F_OK);
	if (exists < 0)
		die3(path, EXIT_FAILURE);
}

static void	read_or_die(char *path)
{
	int	can_read;

	can_read = access(path, R_OK);
	if (can_read < 0)
		die3(path, EXIT_SUCCESS);
}

int	open_file_or_die(char *path)
{
	int	open_fd;
	int	open_flags;

	exists_or_die(path);
	read_or_die(path);
	open_flags = O_RDONLY;
	open_fd = open(path, open_flags);
	if (open_fd < 0)
		die2(path);
	return (open_fd);
}
