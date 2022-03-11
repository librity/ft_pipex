/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 15:17:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	set_print_me(t_printf *print_control,
							t_handle_s *control,
							t_parse_flags *flag_control)
{
	control->print_me = va_arg(print_control->elements, char *);
	control->is_null = (control->print_me == NULL);
	if (control->is_null)
		control->print_me = NULL_STRING;
	control->length = ft_strlen(control->print_me);
	if (flag_control->has_precision
		&& (size_t)flag_control->precision < control->length)
		control->precision_length = flag_control->precision;
	else
		control->precision_length = control->length;
}

static void	initialize_control(t_printf *print_control, t_handle_s *control)
{
	control->print_me = NULL;
	control->length = 0;
	control->precision_length = 0;
	control->is_null = false;
	pf_initialize_flag_control(print_control, &(control->flag_control));
}

/*
** Handles printf's %s conversion.
*/
bool	pf_handled_s(t_printf *print_control)
{
	t_handle_s		control;
	t_parse_flags	*flag_control;

	if (print_control->conversion != 's')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	pf_parse_flags(print_control, flag_control);
	set_print_me(print_control, &control, flag_control);
	pf_print_s(print_control, &control, flag_control);
	return (true);
}
