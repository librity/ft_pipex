/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:16:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Counts the number of chars that a float would have
** if printed with an arbitrary precision.
*/
unsigned int	ft_count_chars_f(float number, int precision)
{
	if (number >= 0)
		return (ft_count_digits_f(number, precision));
	return (ft_count_digits_f(number, precision) + 1);
}
