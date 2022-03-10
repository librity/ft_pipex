/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 18:35:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	die5(char *location, char *message, int exit_status)
{
	ft_putstr("\033[0;31m");
	ft_putstr(location);
	ft_putstr(": ");
	ft_putstr(message);
	exit(exit_status);
}
