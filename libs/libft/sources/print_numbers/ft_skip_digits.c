/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:47:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 21:57:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Advances a char pointer until it stops pointing at an ASCII number.
*/
char	*ft_skip_digits(char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}
