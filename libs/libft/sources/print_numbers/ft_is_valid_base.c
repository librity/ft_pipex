/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:22:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static bool	bad_base_length(const char *base, size_t base_length)
{
	size_t	real_base_length;

	if (base_length == 0 || base_length == 1)
		return (true);
	real_base_length = ft_strlen(base);
	if (real_base_length == 0 || real_base_length == 1)
		return (true);
	if (base_length != real_base_length)
		return (true);
	return (false);
}

static bool	free_and_return(char *free_me, bool is_valid)
{
	if (free_me == NULL)
		return (is_valid);
	free(free_me);
	return (is_valid);
}

/*
** Checks if a string is a valid base for a numberig system:
** - base_length must be greater than 1
** - base_length must equal string length
** - base can't have any repeating chars
*/
bool	ft_is_valid_base(const char *base, const size_t base_length)
{
	size_t	used_position;
	char	*used_characters;

	if (bad_base_length(base, base_length))
		return (false);
	used_characters = ft_salloc(sizeof(char) * (base_length + 1));
	used_characters[0] = '\0';
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (free_and_return(used_characters, false));
		used_position = 0;
		while (used_characters[used_position] != '\0')
		{
			if (used_characters[used_position] == *base)
				return (free_and_return(used_characters, false));
			used_position++;
		}
		used_characters[used_position] = *base;
		used_characters[used_position + 1] = '\0';
		base++;
	}
	return (free_and_return(used_characters, true));
}
