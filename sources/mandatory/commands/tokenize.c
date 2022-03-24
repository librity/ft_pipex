/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/24 01:59:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	subvert_spaces(char *str)
{
	str = ft_strchr(str, '\'');
	while (str != NULL && *str != '\0')
	{
		str++;
		while (*str != '\'' && *str != '\0')
		{
			if (*str == ' ')
				*str = NOT_ASCII;
			str++;
		}
		if (*str == '\'')
			str++;
	}
}

static void	remove_quotes(char *str)
{
	str = ft_strchr(str, '\'');
	while (str != NULL)
	{
		ft_strcpy(str, str + 1);
		str = ft_strchr(str, '\'');
	}
}

static void	restore_spaces(char **tokens)
{
	char	*token;

	while (*tokens != NULL)
	{
		token = *tokens;
		while (*token != '\0')
		{
			if (*token == NOT_ASCII)
				*token = ' ';
			token++;
		}
		tokens++;
	}
}

char	**tokenize_or_die(char *raw_cmd)
{
	char	*free_me;
	char	**tokens;

	if (ft_strchr(raw_cmd, '\'') == NULL)
		return (split_command_or_die(raw_cmd));
	free_me = ft_strdup(raw_cmd);
	subvert_spaces(free_me);
	remove_quotes(free_me);
	tokens = split_command_or_die(free_me);
	restore_spaces(tokens);
	free(free_me);
	return (tokens);
}
