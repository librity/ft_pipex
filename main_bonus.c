/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 07:24:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc < 6)
		return (fourex(argc, argv, envp));
	if (ft_starts_with(argv[1], HEREDOC_IDENT))
		return (heredoc(argc, argv, envp));
	return (nex(argc, argv, envp));
}
