/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 22:27:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc argv.c && ./a.out

#include <stdio.h>

static void	print_arguments(char **arguments)
{
	int	ev_count;

	ev_count = 0;
	printf("=== ARGUMENTS ===\n");
	while (*arguments)
	{
		printf("%s\n", *arguments++);
		ev_count++;
	}
	printf("COUNT: %i\n", ev_count);
}

int	main(int argc, char **argv, char **envp)
{
	print_arguments(argv);
}
