/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Compares n bytes after s1 with the n bytes after s2.
** If any are different it returns the difference.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first_cast;
	unsigned char	*second_cast;

	first_cast = (unsigned char *)s1;
	second_cast = (unsigned char *)s2;
	while (n--)
	{
		if (*first_cast != *second_cast)
			return (*first_cast - *second_cast);
		first_cast++;
		second_cast++;
	}
	return (0);
}
