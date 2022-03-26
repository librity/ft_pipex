/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 19:12:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	print_error(char *location, char *message)
{
	ft_printf("%s%s: %s%s\n", RB, location, message, RC);
}
