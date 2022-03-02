/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 00:40:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	help_and_die(void)
{
	ft_putstr(HELP_MSG);
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr)
{
	if (ptr == NULL)
		die();
}

void	die(void)
{
	perror("\033[0;31mERROR");
	exit(EXIT_FAILURE);
}

void	die_indicated(char *indicator)
{
	ft_putstr("\033[0;31m");
	perror(indicator);
	exit(EXIT_FAILURE);
}