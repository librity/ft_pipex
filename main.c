/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 10:47:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftctemplate.h>
#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;

	x = 10;
	y = 30;
	printf("%d + %d = %d\n", x, y, plus(x, y));
	printf("%d - %d = %d\n", x, y, minus(x, y));
	return (0);
}
