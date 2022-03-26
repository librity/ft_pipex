/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:18:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Calculates the square root of an int.
*/
int	ft_sqrt_i(int number)
{
	unsigned int	square;
	unsigned int	test_root;

	if (number <= 0)
		return (0);
	test_root = 0;
	square = 0;
	while (square <= (unsigned int)number)
	{
		test_root++;
		square = test_root * test_root;
	}
	test_root -= 1;
	if (test_root * test_root != (unsigned int)number)
		return (0);
	return (test_root);
}
