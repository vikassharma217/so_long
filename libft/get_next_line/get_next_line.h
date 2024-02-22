/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:34:57 by vsharma           #+#    #+#             */
/*   Updated: 2023/12/22 23:43:20 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../ft_printf/ft_printf.h"
# include "../libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_buf_str(int fd, char *rest_str);
char	*ft_get_line(char *rest_str);
char	*ft_rest_str(char *rest_str);
char	*ft_strchr_g(char *str, int c);
int		ft_len(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strdup_g(char *s1);

#endif
