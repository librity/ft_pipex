/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/01 21:50:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// TODO: REMOVE FORBIDDEN FUNCTION
void	execute_no_args(char *command)
{
	// TODO: REPLACE WITH execve
	execlp(command, command, NULL);
}
