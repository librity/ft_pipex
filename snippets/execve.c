/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 21:04:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc execve.c && ./a.out

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *argv[] = {"-l", "-a",  NULL};
	char *envp[] = {NULL};

	printf("Main program started\n");
	if (execve("/usr/bin/ls", argv, envp) == -1)
		perror("Could not execve");
	return (1);
}
