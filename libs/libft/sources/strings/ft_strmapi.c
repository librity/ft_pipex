/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:09:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Returns an allocated string with each char modified by f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map_start;
	char	*map;

	map_start = ft_strdup(s);
	if (map_start == NULL)
		return (NULL);
	map = map_start;
	while (*map)
	{
		*map = f(map - map_start, *map);
		map++;
	}
	return (map_start);
}
