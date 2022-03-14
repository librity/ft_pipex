/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/14 16:54:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc char.c && ./a.out

#include <stdio.h>

static void	explore_chars(void)
{
	int	i;

	i = -300;
	while (i < 300)
	{
		printf("|%03d|%02x|%c|\n", i, i, i);
		i++;
	}
}

int	main(void)
{
	printf("=============\n");
	explore_chars();
	printf("=============\n");
	return (0);
}
