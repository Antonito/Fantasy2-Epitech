##
## Makefile for gfx_colle_fantasy2 in /gfx_colle_fantasy2
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Wed Jan 13 18:46:51 2016 Antoine Baché
## Last update Thu Jan 14 05:47:28 2016 Antoine Baché
##

DEBUG=		no

SRC=		src/main.c		\
		src/fill_color.c	\
		src/zelda.c		\
		src/put_circle.c	\
		src/free_all.c

NAME=		zelda

HEAD=		-Iinclude

ifeq ($(DEBUG), yes)
		CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
		CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=		gcc

RM=		rm -f

LIB=		-L/usr/local/lib		\
		-L/home/${USER}/.froot/lib	\
		-I/home/${USER}/.froot/include	\
		-llapin				\
		-lsfml-audio			\
		-lsfml-graphics			\
		-lsfml-window			\
		-lsfml-system			\
		-lstdc++ -ldl			\
		-lm

OBJ=		$(SRC:.c=.o)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "Compiling ..."
	@$(CC) $(OBJ) -o $(NAME) $(LIB)
	@tput setaf 2; tput bold; echo "			OK"
	@tput sgr0

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@tput setaf 2; tput bold; echo "		OK"
	@tput sgr0

fclean:	clean
	@echo -n "Deleting" $(NAME) "..."
	@$(RM) $(NAME)
	@tput setaf 2; tput bold; echo "		OK"
	@tput sgr0

re:	fclean all

.PHONY:	all clean fclean re
