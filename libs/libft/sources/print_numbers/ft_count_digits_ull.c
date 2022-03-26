/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_ull.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:16:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Counts the number of digits that an unsigned long long would have if printed.
*/
unsigned int	ft_count_digits_ull(unsigned long long number)
{
	int	digit_count;

	digit_count = 1;
	number /= 10;
	while (number != 0)
	{
		digit_count++;
		number /= 10;
	}
	return (digit_count);
}
