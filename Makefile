# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkina <rkina@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:59:08 by npetrell          #+#    #+#              #
#    Updated: 2019/11/05 15:39:00 by rkina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./ft_valid_input.c ./ft_valid_corr_tet.c ./main.c \
 ./add_link_list.c ./ft_count_min_s.c ./ft_change_to_coord.c \
./ft_move.c  ./ft_create_map.c ./ft_check_over.c  \
./ft_all_overl.c


OBJECTS=$(SRCS:%.c=%.o)

HEADERS = ./fillit.h

LIB = -L./libft/ -lft 
 
all: $(NAME) $(fillit)

fillit: 
		gcc -Wall -Wextra -Werror -I $(HEADERS) $(SRCS) $(LIB) -o $(NAME)

clean: 
		rm -f $(OBJECTS)
fclean: clean
		rm -f $(NAME)
re: clean all
