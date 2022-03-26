/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits_ul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:04:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Prints the bits of an unsigned long.
*/
void	ft_print_bits_ul(unsigned long x)
{
	int	i;

	ft_putchar('|');
	i = (sizeof(long) * 8) - 1;
	while (i >= 0)
	{
		if (x & (1u << i))
			ft_putchar('1');
		else
			ft_putchar('0');
		if (i % 8 == 0)
			ft_putchar('|');
		i--;
	}
	ft_putchar('\n');
}
