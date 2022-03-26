/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:41:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Scans first n bytes after s for c. Returns c's position if it finds it.
** Returns NULL otherwise.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string_cast;

	string_cast = (unsigned char *)s;
	while (n--)
	{
		if (*string_cast == (unsigned char)c)
			return (string_cast);
		string_cast++;
	}
	return (NULL);
}
