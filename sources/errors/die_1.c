/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 18:35:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	die_if_null(void *ptr)
{
	if (ptr == NULL)
		die2(ERR_NULL_POINTER);
}

void	die(void)
{
	perror(ERR_GENERIC_RED);
	exit(EXIT_FAILURE);
}

void	die2(char *location)
{
	ft_putstr("\033[0;31m");
	perror(location);
	exit(EXIT_FAILURE);
}

void	die3(char *location, int exit_status)
{
	ft_putstr("\033[0;31m");
	perror(location);
	exit(exit_status);
}

void	die4(int exit_status)
{
	perror(ERR_GENERIC_RED);
	exit(exit_status);
}
