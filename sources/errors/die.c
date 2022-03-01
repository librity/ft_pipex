/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	help_and_die(void)
{
	ft_putstr(HELP_MSG);
	exit(EXIT_FAILURE);
}

void	die(void)
{
	perror("ERROR!");
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr)
{
	if (ptr == NULL)
		die();
}
