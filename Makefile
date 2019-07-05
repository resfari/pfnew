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
SRCS=printf.c c.c d.c o.c s.c x.c u.c p.c newint.c proc.c flagsets.c longarifmetika.c longarifmetikaanother.c floatconc.c read_arg.c
OBJECTS=printf.o c.o d.o o.o s.o x.o u.o p.o newint.o proc.o flagsets.o longarifmetika.o longarifmetikaanother.o floatconc.o read_arg.o
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
