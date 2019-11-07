# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:59:08 by npetrell          #+#    #+#              #
#    Updated: 2019/11/07 18:40:35 by npetrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft

CFLAGS = -g -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

CC = gcc

SRCS = ./ft_valid_input.c ./ft_valid_corr_tet.c ./main.c \
 ./ft_add_link_list.c ./ft_count_min_s.c ./ft_change_to_coord.c \
./ft_move.c  ./ft_create_map.c ./ft_check_over.c  \
./ft_fillit.c ./ft_del_list.c

OBJS = $(SRCS:%.c=%.o)

INCLUDES = libft/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
  