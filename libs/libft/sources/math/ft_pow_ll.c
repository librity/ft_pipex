/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:40:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Calculates the power of an arbitrary long long.
*/
long long	ft_pow_ll(long long number, int power)
{
	long long	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	result = result * number * ft_pow_ll(number, power - 1);
	return (result);
}
