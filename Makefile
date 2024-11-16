# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mman <mman@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:03:37 by mman              #+#    #+#              #
#    Updated: 2024/11/16 16:56:41 by mman             ###   ########.fr        #
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

# Colors
GREEN		:= \033[32;1m
YELLOW		:= \033[33;1m
RED			:= \033[31;1m
BLUE		:= \033[34;1m
RESET		:= \033[0m

# Symbols
INFO		:= $(BLUE)ℹ$(RESET)
SUCCESS		:= $(GREEN)✓$(RESET)
WARNING		:= $(YELLOW)⚠$(RESET)
ERROR		:= $(RED)✗$(RESET)

all: $(NAME)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

$(LIBFTDIR):
	/libft

$(MLX): $(MLXDIR)
	cmake $(MLXDIR) -B $(MLXDIR)/build;
	make -C$(MLXDIR)/build -j4;

$(MLXDIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@

$(OBJDIR):
	@printf "$(INFO) Creating directories...\\n"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/raytracer
	@mkdir -p $(OBJDIR)/graphics
	@mkdir -p $(OBJDIR)/clean
	@mkdir -p $(OBJDIR)/math
	@mkdir -p $(OBJDIR)/save_scene
	@printf "$(SUCCESS) Directories created\\n"

$(NAME): $(LIBFT) $(MLX) $(OBJDIR) $(OBJ)
	@printf "$(INFO) Linking $(NAME)...\\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $@
	@printf "$(SUCCESS) $(NAME) ready!\\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/miniRT.h
	@printf "$(YELLOW)Compiling$(RESET) $<...\\r"
	@$(CC) -DCORES=$(NUM_CORES) $(CFLAGS) -c $< $(HEADERS) -o $@
	@printf "$(SUCCESS) Compiled $<                                                    \\n"
clean:
	@printf "$(INFO) Cleaning object files...\\n"
	@$(MAKE) clean -C $(LIBFTDIR) >/dev/null
	@rm -f $(OBJ)
	@printf "$(SUCCESS) Clean complete\\n"

fclean: clean
	@printf "$(INFO) Removing all generated files...\\n"
	@$(MAKE) fclean -C $(LIBFTDIR) >/dev/null
	@rm -rf $(MLXDIR)
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@printf "$(SUCCESS) Full clean complete\\n"

re: fclean all

.PHONY: all clean fclean re
