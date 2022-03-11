/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 07:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
** Prints an unsigned int in uppercase hexadecimal.
*/
void	ft_puthex_uppercase(unsigned int number)
{
	ft_putnbr_base_ui(number, UPPERCASE_HEX_BASE);
}
