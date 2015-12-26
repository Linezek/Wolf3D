##
## Makefile for azert in /home/galpin_a/galpin_a/rendu/infographie/test
## 
## Made by Galpin
## Login   <galpin_a@epitech.net>
## 
## Started on  Wed Nov 18 15:58:45 2015 Galpin
## Last update Sat Dec 26 17:25:17 2015 Galpin
##

NAME		= wolf3d

LDFLAGS		+= -L/home/$(USER)/.froot/lib/ -llapin
LDFLAGS		+= -L/usr/$(USER)/local/lib \
		   -lsfml-audio \
		   -lsfml-graphics \
		   -lsfml-window \
		   -lsfml-system \
		   -lstdc++ -ldl \
		   -lm

CFLAGS		+= -W -Wall -Werror -ansi -pedantic \

SRCS		+= tcore/tekpixel.c \
		   calcul.c \
		   main.c \
		   move.c \
		   tcore/go.c \
		   tcore/vecnorm.c \
		   tools/my_getnbr.c \
		   tools/my_putstr.c 

OBJS		= $(SRCS:.c=.o)

CC		= gcc

ECHO		= echo -e

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled\033[01;34m<-\033[01;34m---------------\033[01;00m'

clean:
	$(RM) $(OBJS)
	@$(ECHO) '\033[01;31m-----------------\033[01;31m->\033[01;33mAll clean\033[01;31m<-\033[01;31m----------------\033[01;00m'

fclean: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[01;36m---------------\033[01;36m->\033[01;36mBinary clean\033[01;36m<-\033[01;36m---------------\033[01;00m'

re: fclean all

.PHONY: all clean fclean re
