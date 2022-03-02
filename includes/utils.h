/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:00:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/02 01:28:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

/******************************************************************************\
 * STRINGS
\******************************************************************************/

size_t	ft_strsize(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_putendl(char *s);

void	ft_putstr_array(char **strings);
size_t	ft_arrlen(void **array);
size_t	ft_arrsize(void **array);
void	ft_free_string_array(char **free_me);

#endif
