# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moguy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 17:01:17 by moguy             #+#    #+#              #
#    Updated: 2019/01/18 20:15:01 by moguy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRCS_NAME = ft_parsing.c \
	   		ft_check_tetri.c \
	   		ft_deltab.c \
	   		ft_error.c \
	  		ft_collect.c \
	   		ft_count.c \
	   		ft_list.c \
	   		ft_tab.c \
	   		ft_resolve.c \
	   		main.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

LIB_NAME = libft.a

LIB_PATH = libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIB) :
		@make -C $(LIB_PATH)

%.o : $(SRCS_PATH)%.c
		$(CC) $(CFLAGS) -c $(SRCS)

clean : $(SRCS)
		@make -C libft/ clean
		@rm -rf $(OBJ)

fclean : clean
		@make -C libft/ fclean
		@rm -rf $(NAME)

re : fclean all
