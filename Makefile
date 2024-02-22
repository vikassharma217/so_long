# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 10:55:27 by vsharma           #+#    #+#              #
#    Updated: 2023/12/23 14:54:27 by vsharma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 		= so_long.c render_game.c render_game1.c \
			render_map.c game_logic.c so_long_utils.c \
			validation.c more_validation.c flood_fill.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
LDFLAGS 	= -lmlx -lX11 -lXext -lm
NAME		= so_long
LIBFT		= libft/
GNL			= libft/get_next_line/
FTPRINTF	= libft/ft_printf/

all: libft gnl ftprintf $(NAME)

libft:
	@$(MAKE) -C $(LIBFT) all

gnl:
	@$(MAKE) -C $(GNL) all

ftprintf:
	@$(MAKE) -C $(FTPRINTF) all

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a $(GNL)gnl.a $(FTPRINTF)libftprintf.a $(LDFLAGS) -o $(NAME)
	

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@$(MAKE) -C $(GNL) clean
	@rm -f $(OBJS)
		
fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(GNL) fclean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all libft gnl ftprintf compile clean fclean re
.SILENT: