/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	parse_precision(t_parse_flags *control)
{
	if (*(control->flags) != '.')
		return ;
	control->flags++;
	control->precision = ft_atoi(control->flags);
	if (control->precision < 0)
	{
		control->precision = 0;
		return ;
	}
	control->has_precision = true;
	control->flags = ft_skip_number(control->flags);
}

static void	parse_width(t_parse_flags *control)
{
	if (unless(ft_is_decimal_char(*(control->flags))))
		return ;
	control->has_minimum_width = true;
	control->minimum_width = ft_atoui(control->flags);
	control->flags = ft_skip_number(control->flags);
}

char	*skip_modifier_noise(char *digits)
{
	while (ft_is_plus_or_minus(*digits) || *digits == '0')
		digits++;
	return (digits);
}

static void	parse_modifiers(t_parse_flags *control)
{
	if (*(control->flags) == '0')
	{
		control->is_left_padded_with_zeros = true;
		control->left_padder = '0';
		while (*(control->flags) == '0')
			control->flags++;
	}
	if (*(control->flags) == '-')
	{
		control->is_left_justified = true;
		control->flags++;
	}
	control->flags = skip_modifier_noise(control->flags);
}

/*
** Parse printf's conversion flags.
*/
void	pf_parse_flags(t_printf *print_control, t_parse_flags *control)
{
	if (print_control->conversion_position == 0)
	{
		(print_control->format)++;
		return ;
	}
	pf_parse_wildcars(print_control, control);
	parse_modifiers(control);
	parse_width(control);
	parse_precision(control);
	if (print_control->conversion != '%')
	{
		if (control->is_left_justified || control->has_precision)
		{
			control->is_left_padded_with_zeros = false;
			control->left_padder = ' ';
		}
	}
	(print_control->format) += (print_control->conversion_position) + 1;
}
