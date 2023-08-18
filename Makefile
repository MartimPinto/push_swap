# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:57:58 by mcarneir          #+#    #+#              #
#    Updated: 2023/08/16 19:40:33 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
NAME_BNS = checker

SRC =	utils.c \
	utils2.c \
	verification.c \

SRC_BNS = 
	
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)

LIBFT = Libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./Libs/libft

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: deps $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) -o $(NAME_BNS)

clean: 
	$(MAKE) clean -C ./Libs/libft
	@$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	@$(RM) $(LIBFT) $(NAME) $(NAME_BNS)

re: fclean all
	