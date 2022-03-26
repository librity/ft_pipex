/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Returns first occurence of char c in string up to limit or NULL.
*/
char	*ft_strnchr(const char *s, int c, unsigned int limit)
{
	unsigned int	current;

	current = 0;
	while (s[current] != (char)c)
	{
		if (s[current] == '\0' || current >= limit)
			return (NULL);
		current++;
	}
	return ((char *)(s + current));
}
