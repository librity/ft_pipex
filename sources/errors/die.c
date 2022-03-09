/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/08 17:44:51 by lpaulo-m         ###   ########.fr       */
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
	perror("\033[0;31mERROR");
	exit(EXIT_FAILURE);
}

void	die2(char *details)
{
	ft_putstr("\033[0;31m");
	perror(details);
	exit(EXIT_FAILURE);
}

void	die3(char *details, int exit_status)
{
	ft_putstr("\033[0;31m");
	perror(details);
	exit(exit_status);
}
