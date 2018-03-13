# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 12:03:38 by lpilotto          #+#    #+#              #
#    Updated: 2016/01/21 20:57:48 by lpilotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT=LINUX
#OUT=MAC
EXEC=fdf
SRC=main.c \
	line.c \
	vector2.c \
	imghelper.c \
	map.c \
	matrix.c \
	point3.c \
	map2d.c
OBJ=$(subst .c,.o,$(SRC))
ifeq ($(OUT),MAC)
  LIBXFOLDER=./minilibx_macos
  LIBX=$(LIBXFOLDER)/libmlx.a
else
  LIBXFOLDER=./minilibx
  LIBX=$(LIBXFOLDER)/libmlx_Linux.a
endif
LIBFTFOLDER=./libft
LIBFT=$(LIBFTFOLDER)/libft.a
EFLAGS=-Wall -Werror -Wextra
IFLAGS=-I$(LIBFTFOLDER) -I./includes -I$(LIBXFOLDER)
ifeq ($(OUT),MAC)
  LFLAGS=-L$(LIBXFOLDER) -lmlx -framework OpenGL -framework AppKit -L$(LIBFTFOLDER) -lft
else
  LFLAGS=-L$(LIBXFOLDER) -lmlx_Linux -lXext -lX11 -L$(LIBFTFOLDER) -lft
endif

.PHONY: all clean fclean re

$(EXEC): $(LIBFT) $(LIBX) $(OBJ)
	gcc -o $(EXEC) $(OBJ) $(LFLAGS)

all: $(EXEC)

%.o: %.c
	gcc -c $< $(EFLAGS) $(IFLAGS) -o $@

$(LIBX):
	make -C $(LIBXFOLDER) all

$(LIBFT):
	make -C $(LIBFTFOLDER) all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)
	make -C $(LIBFTFOLDER) fclean
	make -C $(LIBXFOLDER) clean

re: fclean all
