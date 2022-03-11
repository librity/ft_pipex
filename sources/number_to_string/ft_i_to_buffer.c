/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_to_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	write_digits(char *string,
							unsigned int char_count,
							unsigned int number,
							int is_negative)
{
	string[char_count] = '\0';
	while (char_count--)
	{
		string[char_count] = '0' + (number % 10);
		number /= 10;
	}
	if (is_negative)
		string[0] = '-';
}

/*
** Parses an int and writes it to a previously-allocated buffer.
*/
unsigned int	ft_i_to_buffer(int n, char *buffer)
{
	unsigned int	char_count;
	unsigned int	number;
	unsigned int	is_negative;

	char_count = ft_count_chars_i(n);
	number = (unsigned int)n;
	is_negative = 0;
	if (n < 0)
	{
		number *= -1;
		is_negative = 1;
	}
	write_digits(buffer, char_count, number, is_negative);
	return (char_count);
}
