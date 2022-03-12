/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:00:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 20:00:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/******************************************************************************\
 * ARRAYS
\******************************************************************************/

size_t	ft_arrlen(void **array);
size_t	ft_arrsize(void **array);

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

void	ft_free_string_array(char **free_me);

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

void	ft_putendl(char *s);
void	ft_putstr_array(char **strings);

/******************************************************************************\
 * LINKED_LISTS
\******************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstnew_safe(void *content);

t_list	*ft_lstmap(t_list *lst,
			void *(*f)(void *),
			void (*del)(void *));
t_list	*ft_lstmap_safe(t_list *lst, void *(*f)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstlast(t_list *lst);

int		ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lst_append(t_list **lst, void *content);
void	ft_lst_prepend(t_list **lst, void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

/******************************************************************************\
 * LISTED MEMORY ALLOCATION
\******************************************************************************/

void	*ft_lalloc(t_list **lalloc, size_t size);
void	ft_add_lalloc(t_list **lalloc, void *pointer);
void	ft_add_lalloc_array(t_list **lalloc, void **pointer);
void	ft_free_lalloc(t_list **free_me);

#endif
