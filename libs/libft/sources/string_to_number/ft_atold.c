/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Takes in a string and parses its chars into a long double.
*/
long double	ft_atold(const char *str)
{
	long double	number;
	long double	power;
	int			sign;

	number = 0.0;
	power = 1.0;
	sign = 1;
	str = ft_skip_whitespace((char *)str);
	if (ft_is_plus_or_minus(*str))
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		number = number * 10.0 + (*str++ - '0');
	if (*str++ != '.')
		return (sign * number);
	while (ft_isdigit(*str))
	{
		number = number * 10.0 + (*str++ - '0');
		power *= 10.0;
	}
	return (sign * number / power);
}
