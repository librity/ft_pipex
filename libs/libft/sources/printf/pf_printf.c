/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:16:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Prints ints, floats and strings according to a format string.
*/
int	ft_printf(const char *format, ...)
{
	t_printf	print_control;

	pf_initialize_print_control(&print_control, format);
	va_start(print_control.elements, format);
	pf_vprintf(&print_control);
	va_end(print_control.elements);
	return (print_control.chars_printed);
}
