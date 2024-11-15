# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mman <mman@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:03:37 by mman              #+#    #+#              #
#    Updated: 2024/11/09 15:26:00 by mman             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE		:= make
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Wunreachable-code -Ofast
SRCDIR		:= ./src
OBJDIR		:= ./obj
INCDIR		:= ./inc
LIBFTDIR	:= ./libft
LIBFT		:= $(LIBFTDIR)/libft.a
MLXDIR		:= ./MLX42
MLX			:= $(MLXDIR)/build/libmlx42.a
HEADERS		:= -I$(INCDIR) -I$(LIBFTDIR)/inc -I$(MLXDIR)/include/MLX42
LIBS		:= -L$(LIBFTDIR) -lft $(MLX)
NUM_CORES	:= 8
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	:= $(LIBS) -ldl -lglfw -lm -pthread
	NUM_CORES	:= $(shell nproc)
endif
ifeq ($(UNAME_S),Darwin)
	LIBS	:= $(LIBS) -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/" -lm -pthread
	NUM_CORES	:= $(shell sysctl -n hw.logicalcpu)
endif
SRC			:= main.c \
				clean/clean.c \
				clean/exit.c \
				graphics/hooks.c \
				graphics/put_pixel.c \
				graphics/colors.c \
				graphics/rotations.c \
				graphics/set_direction.c \
				graphics/translate.c \
				math/math_utils.c \
				math/vector_utils_norm.c \
				math/vector_utils.c \
				parser/check_vector.c \
				parser/parser_camera.c \
				parser/parser_checks.c \
				parser/parser_cyl.c \
				parser/parser_disk.c \
				parser/parser_lights.c \
				parser/parser_objects.c \
				parser/parser_real.c \
				parser/parser_utils.c \
				parser/parser.c \
				raytracer/anti_alias.c \
				raytracer/compute_color_utils.c \
				raytracer/compute_color.c \
				raytracer/compute_rays.c \
				raytracer/cyl_utils.c \
				raytracer/cyl.c \
				raytracer/intersections.c \
				raytracer/raytracer.c \
				save_scene/save_scene.c \
				save_scene/save_scene_utils.c \
				save_scene/write_object.c
SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
OBJ			:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
NAME		:= miniRT

all: $(NAME)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

$(LIBFTDIR):
	git clone https://github.com/MartijnWallage/42_libft.git $@

$(MLX): $(MLXDIR)
	cmake $(MLXDIR) -B $(MLXDIR)/build;
	make -C$(MLXDIR)/build -j4;

$(MLXDIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@

$(OBJDIR):
	mkdir $(OBJDIR);
	mkdir $(OBJDIR)/parser;
	mkdir $(OBJDIR)/raytracer;
	mkdir $(OBJDIR)/graphics;
	mkdir $(OBJDIR)/clean;
	mkdir $(OBJDIR)/math;
	mkdir $(OBJDIR)/save_scene;

$(NAME): $(LIBFT) $(MLX) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/miniRT.h
	$(CC) -DCORES=$(NUM_CORES) $(CFLAGS) -c $< $(HEADERS) -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -rf $(MLXDIR)
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
