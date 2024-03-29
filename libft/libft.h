/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:23:53 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/22 22:20:51 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		ft_isalnum(int c);
int		ft_isalpha(int alpha);
int		ft_isascii(int c);
int		ft_isdigit(int digit);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memchr(const void *string, int c, size_t n);
int		ft_memcmp(const void *string1, const void *string2, size_t n);
void	*ft_memset(void *string, int c, size_t n);
void	ft_bzero(void *string, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_strrchr(const char *string, int c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
