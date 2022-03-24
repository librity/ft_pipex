/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 07:45:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static void	help_and_die_nex(void)
{
	ft_putstr(HELP_MSG_NEX);
	exit(EXIT_SUCCESS);
}

void	check_argc_nex(int argc)
{
	if (argc > 5)
		return ;
	help_and_die_nex();
}

static void	help_and_die_hd(void)
{
	ft_putstr(HELP_MSG_HEREDOC);
	exit(EXIT_SUCCESS);
}

void	check_argc_hd(int argc)
{
	if (argc > 5)
		return ;
	help_and_die_hd();
}
