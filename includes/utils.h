/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:00:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/11 15:07:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

/******************************************************************************\
 * BOOLEANS
\******************************************************************************/

bool			unless(bool condition);

/******************************************************************************\
 * MATH
\******************************************************************************/

int				ft_pow(int number, int power);
int				ft_pow_i(int number, int power);

/******************************************************************************\
 * MEMORY
\******************************************************************************/

# define MALLOC_ERROR_MESSAGE "ERROR: Unable to allocate required memory.\n"

void			*ft_salloc(size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);

/******************************************************************************\
 * CHARS
\******************************************************************************/

bool			ft_is_decimal_char(char character);
bool			ft_is_plus_or_minus(char character);
bool			ft_is_whitespace(char character);
bool			ft_isdigit(int c);

/******************************************************************************\
 * STRINGS
\******************************************************************************/

size_t			ft_strlen(const char *s);
size_t			ft_strsize(const char *s);

char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

char			*ft_strnstr(const char *haystack,
					const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c, unsigned int limit);
char			*ft_strchr(const char *s, int c);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *free_me, char const *dont_free_me);
char			*ft_strjoin_free_free(char *free_me, char *free_me_too);

/******************************************************************************\
 * STRING TO NUMBER
\******************************************************************************/

int				ft_atoi(const char *number_pointer);
unsigned int	ft_atoui(const char *number_pointer);

/******************************************************************************\
 * NUMBER TO STRING
\******************************************************************************/

unsigned int	ft_i_to_buffer(int n, char *buffer);

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putstr_up_to(char *s, size_t up_to);

void			ft_putendl(char *s);

void			ft_putstr_array(char **strings);
size_t			ft_arrlen(void **array);
size_t			ft_arrsize(void **array);
void			ft_free_string_array(char **free_me);

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

# define DEFAULT_PRINT_FLOAT_PRECISION 6

# define DECIMAL_BASE "0123456789"
# define LOWERCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

bool			ft_is_valid_base(const char *base,
					const size_t base_length);

void			ft_aux_handle_minus_sign_l(long *number_pointer);
void			ft_aux_handle_minus_sign_ll(long long *number_pointer);

void			ft_aux_handle_minus_sign_d(double *number_pointer);
void			ft_aux_handle_minus_sign_ld(long double *number_pointer);

void			ft_putnbr_ui(unsigned int number);
void			ft_putnbr_l(long number);
void			ft_putnbr_ll(long long number);

void			ft_putnbr_base_ui(unsigned int number, const char *base);
void			ft_putnbr_base_l(long number, const char *base);
void			ft_putnbr_base_ul(unsigned long number, const char *base);
void			ft_putnbr_base_ll(long long number, const char *base);

void			ft_putnbr_precise_d(double n, int precision);
void			ft_putnbr_precise_ld(long double n, int precision);

void			ft_puthex_uppercase(unsigned int number);
void			ft_puthex_lowercase(unsigned int number);

unsigned int	ft_count_digits(int number);
unsigned int	ft_count_digits_i(int number);
unsigned int	ft_count_digits_ui(unsigned int number);
unsigned int	ft_count_digits_ull(unsigned long long number);

unsigned int	ft_count_digits_hex_ul(unsigned long number);

unsigned int	ft_count_chars_i(int number);

unsigned int	ft_count_chars_d(double number, int precision);
unsigned int	ft_count_digits_d(double number, int precision);

unsigned int	ft_count_chars_ld(long double number, int precision);
unsigned int	ft_count_digits_ld(long double number, int precision);

char			*ft_skip_number(char *digits);
char			*ft_skip_whitespace(char *digits);

/******************************************************************************\
 * LINKED_LISTS
\******************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstnew_safe(void *content);

t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstmap_safe(t_list *lst, void *(*f)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstlast(t_list *lst);

int				ft_lstsize(t_list *lst);

void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));

#endif
