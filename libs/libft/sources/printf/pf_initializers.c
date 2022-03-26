/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:49:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** Initialize printf's general control.
*/
void	pf_initialize_print_control(t_printf *print_control, const char *format)
{
	print_control->format = format;
	print_control->chars_printed = 0;
	print_control->conversion_position = 0;
	print_control->conversion = '\0';
}

/*
** Initialize printf's flag control.
*/
void	pf_initialize_flag_control(t_printf *print_control,
								t_parse_flags *flag_control)
{
	flag_control->flags = (char *)(print_control->format);
	flag_control->has_wildcards = false;
	flag_control->is_left_padded_with_zeros = false;
	flag_control->is_left_justified = false;
	flag_control->left_padder = ' ';
	flag_control->has_minimum_width = false;
	flag_control->minimum_width = 0;
	flag_control->has_precision = false;
	flag_control->precision = 0;
}

/*
** Initialize printf's wildcard control.
*/
void	pf_initialize_wildcard_control(t_printf *print_control,
									t_parse_flags *flag_control,
									t_parse_wildcards *wildcard_control)
{
	wildcard_control->conversion_position = print_control->conversion_position;
	wildcard_control->found_wildcards = ft_strnchr(flag_control->flags, '*',
			wildcard_control->conversion_position);
	wildcard_control->parser = 0;
	wildcard_control->wildcard = 0;
}
