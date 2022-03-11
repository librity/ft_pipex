/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_wildcars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	handle_wildcard(t_printf *print_control,
							t_parse_flags *flag_control,
							t_parse_wildcards *control)
{
	control->wildcard = va_arg(print_control->elements, int);
	control->parser += ft_i_to_buffer(control->wildcard,
			flag_control->parsed_flags + control->parser);
	(flag_control->flags)++;
	control->conversion_position--;
}

static bool	handled_default(t_parse_flags *flag_control,
							t_parse_wildcards *control)
{
	if (*(flag_control->flags) == '*')
		return (false);
	flag_control->parsed_flags[control->parser] = *(flag_control->flags);
	(flag_control->flags)++;
	(control->parser)++;
	control->conversion_position--;
	return (true);
}

/*
** Parse printf's wildcards.
*/
void	pf_parse_wildcars(t_printf *print_control,
					t_parse_flags *flag_control)
{
	t_parse_wildcards	control;

	pf_initialize_wildcard_control(print_control, flag_control, &control);
	if ((control.found_wildcards) == NULL)
		return ;
	flag_control->has_wildcards = true;
	while ((control.conversion_position) > 0 && *(flag_control->flags) != '\0')
	{
		if (handled_default(flag_control, &control))
			continue ;
		handle_wildcard(print_control, flag_control, &control);
	}
	(flag_control->parsed_flags)[control.parser] = '\0';
	flag_control->flags = flag_control->parsed_flags;
}
