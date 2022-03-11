/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:00:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 01:03:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

/******************************************************************************\
 * STRINGS
\******************************************************************************/

char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strsize(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *free_me, char const *dont_free_me);
char	*ft_strjoin_free_free(char *free_me, char *free_me_too);

void	ft_putendl(char *s);

void	ft_putstr_array(char **strings);
size_t	ft_arrlen(void **array);
size_t	ft_arrsize(void **array);
void	ft_free_string_array(char **free_me);

#endif
