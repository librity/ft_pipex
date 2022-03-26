/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:45:31 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/25 22:46:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc wait.c && ./a.out

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	wstatus;
	pid_t cpid, w;

	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{ /* Code executed by child */
		printf("Child PID is %jd\n", (intmax_t)getpid());
		if (argc == 1)
			pause(); /* Wait for signals */
		_exit(atoi(argv[1]));
	}
	else
	{ /* Code executed by parent */
		do
		{
			w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
			if (w == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(wstatus))
			{
				printf("exited, status=%d\n", WEXITSTATUS(wstatus));
			}
			else if (WIFSIGNALED(wstatus))
			{
				printf("killed by signal %d\n", WTERMSIG(wstatus));
			}
			else if (WIFSTOPPED(wstatus))
			{
				printf("stopped by signal %d\n", WSTOPSIG(wstatus));
			}
			else if (WIFCONTINUED(wstatus))
			{
				printf("continued\n");
			}
		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
		exit(EXIT_SUCCESS);
	}
}
