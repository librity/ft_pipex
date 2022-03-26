/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 07:42:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	print_number_with_base(unsigned int number,
									const size_t base_length,
									const char *base)
{
	if (number >= base_length)
		print_number_with_base(number / base_length, base_length, base);
	ft_putchar(base[number % base_length]);
}

/*
** Prints an unsigned int in an arbitrary base.
*/
void	ft_putnbr_base_ui(unsigned int number, const char *base)
{
	size_t	base_length;

	base_length = ft_strlen(base);
	if (unless(ft_is_valid_base(base, base_length)))
		return ;
	print_number_with_base(number, base_length, base);
}
