/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/10 23:44:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc char.c && ./a.out

#include <stdio.h>

static void	explore_chars(void)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 300)
	{
		printf("%i: |%c|\n", i, c);
		c++;
		i++;
	}
}

int	main(void)
{
	printf("\n=============\n");
	explore_chars();
	printf("\n=============\n");
	return (0);
}
