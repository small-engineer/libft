/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:08:48 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/30 18:21:07 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				*ft_memset(void *ptr, int value, size_t num);
void				*ft_memcpy(void *dst, const void *src, size_t num);
void				*ft_memccpy(void *dst, const void *src, int c, size_t num);
void				*ft_memmove(void *dst, const void *src, size_t num);
void				*ft_memchr(const void *ptr, int c, size_t num);
void				ft_bzero(void *ptr, size_t num);
int					ft_memcmp(const void *s1, const void *s2, size_t num);

void				*ft_calloc(size_t num, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);

#endif
