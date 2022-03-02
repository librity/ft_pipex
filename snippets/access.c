/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:55:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 01:02:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc access.c && ./a.out

#include <stdio.h>
#include <unistd.h>

static void	putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, (s++), 1);
}

static void handle_error(char *file, int access_result)
{
	if (access_result < 0)
	{
		putstr("	===> ");
		perror(file);
	}
}

static void	test_access(char *file)
{
	int access_result;

	// TEST IF FILE EXISTS
	printf("\n=== %s ===\n", file);
	access_result = access(file, F_OK);
	printf("	F_OK: %i\n", access_result);
	handle_error(file, access_result);

	// TEST READ PERMISSION
	access_result = access(file, R_OK);
	printf("	R_OK: %i\n", access_result);
	handle_error(file, access_result);

	// TEST WRITE PERMISSION
	access_result = access(file, W_OK);
	printf("	W_OK: %i\n", access_result);
	handle_error(file, access_result);

	// TEST EXECUTE PERMISSION
	access_result = access(file, X_OK);
	printf("	X_OK: %i\n", access_result);
	handle_error(file, access_result);

	// TEST ALL PERMISSIONS
	access_result = access(file, F_OK | R_OK | W_OK | X_OK);
	printf("	ALL FLAGS: %i\n", access_result);
	handle_error(file, access_result);
}

int	main(int argc, char **argv, char **envp)
{
	test_access("/usr/bin/ls");
	test_access("infile");
	test_access("outfile");
	test_access("no_permissions");

	return (0);
}
