/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:11:41 by abesneux          #+#    #+#             */
/*   Updated: 2024/09/25 15:40:50 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// PREMIERE PARTIE
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strchr(char *str, char c);
char				*ft_strrchr(const char *str, int c);
size_t				ft_strlen(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *destination, const void *source,
						size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *memoryBlock, int searchedChar,
						size_t size);
int					ft_strncmp(char *s1, char *s2, int n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, char *src, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				**ft_split(const char *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strndup(char *str, unsigned int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t len);
char				*ft_strstr(const char *str1, const char *str2);
// BONUS
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char				*get_next_line(int fd);
int					ft_check(char *s);
void				ft_buf_cut(char *dest);
int					ft_len(char *s, int j);
char				*ft_join(char *s1, char *s2);
char				*test(char *s1, char *dest);

// Printf
int					ft_putchar(int c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putnbr_un(unsigned int n);
int					ft_nbrbase(unsigned long nbr, char *base, bool ptr);
int					ft_format(va_list args, const char format);
int					ft_printf(const char *format, ...);
int					ft_strlen_printf(char *s);

#endif
