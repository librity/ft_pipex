/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_handle_minus_sign_f.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:31:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:51:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/*
** If a float is negative, prints the minus sign and flips it.
*/
void	ft_aux_handle_minus_sign_f(float *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}
