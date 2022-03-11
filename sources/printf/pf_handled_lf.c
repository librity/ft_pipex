/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_lf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	set_print_me(t_printf *pf_ctl, t_handle_lf *control)
{
	control->print_me = va_arg(pf_ctl->elements, long double);
	if (control->print_me < 0)
		control->is_negative = true;
}

static void	initialize_control(t_printf *pf_ctl,
								t_handle_lf *control)
{
	control->print_me = 0;
	control->digit_count = 0;
	control->char_count = 0;
	control->is_negative = false;
	control->is_zero_with_zero_precision = false;
	pf_initialize_flag_control(pf_ctl, &(control->flag_control));
}

static void	interpret_flags(t_parse_flags *flag_control,
	t_handle_lf *control)
{
	if (flag_control->has_precision)
		if (flag_control->precision == 0 && control->print_me == 0)
			control->is_zero_with_zero_precision = true;
	if (unless(flag_control->has_precision))
		flag_control->precision = 6;
	control->char_count = ft_count_chars_ld(control->print_me,
			flag_control->precision);
	control->digit_count = ft_count_digits_ld(control->print_me,
			flag_control->precision);
}

/*
** Handles printf's %Lf conversion.
*/
bool	pf_handled_lf(t_printf *pf_ctl)
{
	t_handle_lf		control;
	t_parse_flags	*flag_control;

	if (pf_ctl->conversion != 'L'
		&& (pf_ctl->format)[pf_ctl->conversion_position + 1] != 'f')
		return (false);
	initialize_control(pf_ctl, &control);
	flag_control = &(control.flag_control);
	pf_parse_flags(pf_ctl, flag_control);
	pf_ctl->format++;
	set_print_me(pf_ctl, &control);
	interpret_flags(flag_control, &control);
	pf_print_lf(pf_ctl, &control, flag_control);
	return (true);
}
