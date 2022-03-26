/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:46:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/22 21:57:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Skips '+'ses and '-'ses, then skips ASCII numbers.
*/
char	*ft_skip_number(char *str)
{
	while (ft_is_plus_or_minus(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	return (str);
}
