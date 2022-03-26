/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:41:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Set the memory from s to s + n to an unsigned char c.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointerator;
	unsigned char	casted_char;

	pointerator = s;
	casted_char = (unsigned char)c;
	while (n--)
	{
		*pointerator = casted_char;
		pointerator++;
	}
	return (s);
}
