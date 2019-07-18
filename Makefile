# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/04/10 15:21:38 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=printf
SRCS=flagsets.c \
		  d.c \
		  o.c \
		  s.c \
		  longarifmetika.c \
		  longarifmetikaanother.c \
		  floatconc.c \
		  printf.c \
		  read_arg.c \
		  x.c \
		  proc.c \
		  c.c \
		  newint.c \
		  u.c \
		  p.c \
		  d2.c \
		  flagsetspart2.c \
		  norm.c \
		  norm2.c \
		  check_beats.c \
		  float_other.c \
		  mantisa_calc.c \
		  calc_summ.c \
		  infinity.c \
		  nan.c \
		  
FLAG=-Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(FLAG) $(SRCS) -Llibft -lft

clean:
	/bin/rm -f *.o
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
	make -C libft re
