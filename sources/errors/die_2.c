/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 19:35:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	die5(char *location, char *message, int exit_status)
{
	ft_printf("\033[0;31m%s: %s\n", location, message);
	exit(exit_status);
}
