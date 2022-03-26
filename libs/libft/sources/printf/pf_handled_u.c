/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	set_print_me(t_printf *print_control, t_handle_u *control)
{
	control->print_me = va_arg(print_control->elements, unsigned int);
	control->digit_count = ft_count_digits_ui(control->print_me);
}

static void	initialize_control(t_printf *print_control,
								t_handle_u *control)
{
	control->print_me = 0;
	control->digit_count = 0;
	control->is_zero_with_zero_precision = false;
	pf_initialize_flag_control(print_control, &(control->flag_control));
}

static void	interpret_flags(t_parse_flags *flag_control, t_handle_u *control)
{
	if (flag_control->has_precision)
		if (flag_control->precision == 0 && control->print_me == 0)
			control->is_zero_with_zero_precision = true;
}

/*
** Handles printf's %u conversion.
*/
bool	pf_handled_u(t_printf *print_control)
{
	t_handle_u		control;
	t_parse_flags	*flag_control;

	if (print_control->conversion != 'u')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	pf_parse_flags(print_control, flag_control);
	set_print_me(print_control, &control);
	interpret_flags(flag_control, &control);
	pf_print_u(print_control, &control, flag_control);
	return (true);
}
