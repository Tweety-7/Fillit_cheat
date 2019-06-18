# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 18:52:38 by kwalter           #+#    #+#              #
#    Updated: 2019/06/12 17:51:09 by kwalter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

HEAD = ./head

LIBFT = libft/libft.a

SRC = main.c\
		rec_fillit.c\
		new_map.c\
		new_empty_map.c\
		valid_map.c\
		get_next_line/get_next_line.c\
		ft_min_l_sq.c\

CMP2 = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(CMP2)
		gcc -o $(NAME) $(FLAGS) $(CMP2) -L. $(LIBFT) -I $(HEAD)

$(LIBFT):
		@make -C libft/

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
		rm -f $(CMP2)
		@make -C libft/ clean

fclean: clean
		rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all
