# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:57:58 by mcarneir          #+#    #+#              #
#    Updated: 2023/09/01 11:38:18 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap


SRC =	src/utils.c \
		src/utils2.c \
		src/verification.c \
		src/operations.c \
		src/free.c \
		src/sort.c \
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
	