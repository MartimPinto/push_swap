# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:57:58 by mcarneir          #+#    #+#              #
#    Updated: 2023/09/06 16:02:52 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = push_swap


SRC =	src/utils.c \
		src/utils2.c \
		src/index.c \
		src/verification.c \
		src/operations.c \
		src/operations2.c \
		src/free.c \
		src/small_sort.c \
		src/big_sort.c \
		src/position.c \
		src/cost.c \
		src/main.c \


	
OBJ = $(SRC:.c=.o)

LIBFT = Libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./Libs/libft

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean: 
	$(MAKE) clean -C ./Libs/libft
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean all
	