/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	handle_precision(t_printf *print_control,
								t_handle_hex *control,
								t_parse_flags *flag_control)
{
	int	precision;

	if (unless(flag_control->has_precision))
		return ;
	if (flag_control->precision < (int)control->digit_count)
		return ;
	precision = flag_control->precision - control->digit_count;
	if (precision < 0)
		precision = 0;
	(print_control->chars_printed) += precision;
	while (precision--)
		ft_putchar('0');
}

static void	handle_padding(t_printf *print_control,
							t_handle_hex *control,
							t_parse_flags *flag_control)
{
	int	padding;

	if (flag_control->has_precision)
		if (flag_control->precision >= flag_control->minimum_width)
			if (unless(control->is_zero_with_zero_precision))
				return ;
	if (flag_control->has_precision
		&& (flag_control->precision > control->digit_count))
		padding = flag_control->minimum_width - flag_control->precision;
	else
		padding = flag_control->minimum_width - control->digit_count;
	if (control->is_zero_with_zero_precision)
		padding++;
	if (padding <= 0)
		return ;
	(print_control->chars_printed) += padding;
	while (padding--)
		ft_putchar(flag_control->left_padder);
}

static void	handle_left(t_printf *print_control,
						t_handle_hex *control,
						t_parse_flags *flag_control)
{
	if (unless(flag_control->is_left_justified))
		handle_padding(print_control, control, flag_control);
	handle_precision(print_control, control, flag_control);
}

/*
** Prints the formatted conversions %x and %X.
*/
void	pf_printf_hex(t_printf *print_control,
				t_handle_hex *control,
				t_parse_flags *flag_control)
{
	handle_left(print_control, control, flag_control);
	if (control->is_zero_with_zero_precision)
	{
		if (flag_control->is_left_justified)
			handle_padding(print_control, control, flag_control);
		return ;
	}
	if (control->is_uppercase)
		ft_puthex_uppercase(control->print_me);
	else
		ft_puthex_lowercase(control->print_me);
	(print_control->chars_printed) += control->digit_count;
	if (flag_control->is_left_justified)
		handle_padding(print_control, control, flag_control);
}
