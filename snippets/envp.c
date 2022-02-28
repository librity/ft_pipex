/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 21:19:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc envp.c && ./a.out

#include <stdio.h>

static void print_environment_variables(char **environment_variables)
{
	int ev_count;

	ev_count = 0;
	printf("=== ENVIRONMENT VARIABLES ===\n");
	while (*environment_variables)
	{
		printf("%s\n", *environment_variables++);
		ev_count++;
	}
	printf("COUNT: %i\n", ev_count);
}

int	main(int argc, char **argv, char **envp)
{
	print_environment_variables(envp);
}
