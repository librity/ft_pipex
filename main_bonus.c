/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 18:55:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	check_argc_b(argc);
	if (ft_starts_with(argv[1], HDOC_IDENTIFIER))
		return (hdoc(argc, argv, envp));
	// if (argc < 6)
	// 	return (fourex(argc, argv, envp));
	return (nex(argc, argv, envp));
}
