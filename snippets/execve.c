/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/27 23:24:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc execve.c && ./a.out

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char *ls_args[] = {"-l", "-a",  NULL};

	printf("Main program started\n");
	if (execve("/usr/bin/ls", ls_args, envp) == -1)
		perror("Could not execve");
	return (0);
}
