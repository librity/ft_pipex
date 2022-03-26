/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Finds the first occurence of needle in haystack up to length.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_start;
	char	*needle_pointerator;
	char	*possible_match;

	haystack_start = (char *)haystack;
	if (*needle == '\0')
		return (haystack_start);
	while (*haystack)
	{
		needle_pointerator = (char *)needle;
		possible_match = (char *)haystack;
		while (*needle_pointerator
			&& *haystack == *needle_pointerator
			&& (unsigned long)(haystack - haystack_start) < len)
		{
			needle_pointerator++;
			haystack++;
		}
		if (*needle_pointerator == '\0')
			return (possible_match);
		haystack = possible_match + 1;
	}
	return (NULL);
}
