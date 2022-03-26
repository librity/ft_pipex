/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	handle_padding(t_printf *print_control,
							t_handle_c *control,
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
** Prints the formatted conversion %c.
*/
void	pf_print_c(t_printf *print_control,
				t_handle_c *control,
				t_parse_flags *flag_control)
{
	if (unless(flag_control->is_left_justified))
		handle_padding(print_control, control, flag_control);
	ft_putchar(control->print_me);
	(print_control->chars_printed) += control->char_count;
	if (flag_control->is_left_justified)
		handle_padding(print_control, control, flag_control);
}
