/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	set_print_me(t_printf *print_control, t_handle_hex *control)
{
	control->print_me = va_arg(print_control->elements, unsigned int);
	control->digit_count = ft_count_digits_hex_ul(control->print_me);
}

static void	initialize_control(t_printf *print_control,
								t_handle_hex *control)
{
	control->print_me = 0;
	control->digit_count = 0;
	control->is_uppercase = (print_control->conversion == 'X');
	control->is_zero_with_zero_precision = false;
	pf_initialize_flag_control(print_control, &(control->flag_control));
}

static void	interpret_flags(t_parse_flags *flag_control, t_handle_hex *control)
{
	if (flag_control->has_precision)
		if (flag_control->precision == 0 && control->print_me == 0)
			control->is_zero_with_zero_precision = true;
}

/*
** Handles printf's %x and %X conversions.
*/
bool	pf_handled_hex(t_printf *print_control)
{
	t_handle_hex	control;
	t_parse_flags	*flag_control;

	if (print_control->conversion != 'x' && print_control->conversion != 'X')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	pf_parse_flags(print_control, flag_control);
	set_print_me(print_control, &control);
	interpret_flags(flag_control, &control);
	pf_printf_hex(print_control, &control, flag_control);
	return (true);
}
