# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:11:22 by lgarczyn          #+#    #+#              #
#    Updated: 2015/01/22 17:13:56 by lgarczyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lgarczyn.filler
NAME_D = display

SRC =	parsing.c \
		checking.c \
		scoring.c \
		influence.c \
		tools.c \
		distance.c \
		
OBJ = $(SRC:.c=.o)

INC = libft/includes

LIB = -L libft/ -lft

DEB = 

OPT = -Ofast

FLG = -Wall -Wextra -Werror $(OPT) $(DEB)

all: $(NAME)

libft.a:
	cd libft && make all

$(NAME):$(OBJ) display.o filler.o libft.a
	gcc filler.o $(OBJ) $(FLG) $(LIB) -L libft -lft -o $(NAME)
	gcc display.o $(OBJ) $(FLG) $(LIB) -L libft -lft -o $(NAME_D)
	cp $(NAME) resources/players
	cp $(NAME_D) resources
	
%.o: %.c
	gcc -I$(INC) $(FLG) -c $< $

clean:
	rm -rf $(OBJ) display.o filler.o
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_D)
	cd libft && make fclean

re: fclean all

cleannolib:
	rm -rf $(OBJ) display.o filler.o
	rm -rf $(NAME)
	rm -rf $(NAME_D)

smart: cleannolib all
