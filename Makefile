#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 20:21:28 by gmevelec          #+#    #+#              #
#    Updated: 2014/01/14 18:23:46 by gmevelec         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRCDIR = src/
LIBDIR = obj/
HEADDIR = inc
CFLAGS = -g -Wall -Wextra -I$(HEADDIR) 
LFLAGS = -L/usr/X11/lib -lmlx -lX11 -lXext -lm

SRC = $(SRCDIR)wolf3d.c $(SRCDIR)image.c $(SRCDIR)move.c $(SRCDIR)draw.c \
	$(SRCDIR)print.c $(SRCDIR)ft_check.c $(SRCDIR)ft_init.c $(SRCDIR)ft_calc.c

TSRC=$(subst src/,../src/,$(SRC))

TMP=$(subst src/,obj/,$(SRC))

OBJ = $(TMP:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@llvm-gcc -o $(NAME) $(OBJ) $(LFLAGS)
		@echo "Creating $(NAME)"

$(OBJ) : $(SRC)
		@mkdir -p $(LIBDIR);
		@(cd obj;llvm-gcc -c $(TSRC) $(CFLAGS))
		@echo "Creating .o"

clean :
		@rm -f $(OBJ)
		@echo "Suppressing all .o"

fclean : clean
		@rm -f $(NAME)
		@echo "Suppressing $(NAME)"

re : fclean all

.PHONY: all clean fclean re
