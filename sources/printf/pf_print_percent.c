/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 15:17:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	handle_padding(t_printf *print_control,
							t_handle_percent *control,
							t_parse_flags *flag_control)
{
	int	padding;

	padding = flag_control->minimum_width - control->char_count;
	if (padding <= 0)
		return ;
	(print_control->chars_printed) += padding;
	while (padding--)
		ft_putchar(flag_control->left_padder);
}

/*
** Prints the formatted conversion %%.
*/
void	pf_print_percent(t_printf *print_control,
					t_handle_percent *control,
					t_parse_flags *flag_control)
{
	if (unless(flag_control->is_left_justified))
		handle_padding(print_control, control, flag_control);
	ft_putchar(control->print_me);
	(print_control->chars_printed) += control->char_count;
	if (flag_control->is_left_justified)
		handle_padding(print_control, control, flag_control);
}
