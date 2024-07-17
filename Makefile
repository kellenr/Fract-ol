# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 17:06:07 by keramos-          #+#    #+#              #
#    Updated: 2024/05/20 15:34:12 by keramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -g

LIBFT = ./Libft/libft.a

LIB = ../mlx/libmlx.a

MLXFLAGS = -L../mlx -lXext -lX11 -lm

INCLUDES = -I inc \
			-I Libft/inclu \
			-I ../mlx/

RM = rm -rf

#                         Color and Checkmark Definitions                      #

LILAC=\033[1;38;5;183m
PINK=\033[1;38;5;213m
BABY_BLUE = \033[1;38;5;153m
ORG =\033[38;5;216m
BLUE=\033[1;34m
AQUA=\033[1;38;5;79m
AQUA_L=\033[38;5;51m
CHECK = \033[0;34m✔\033[0m
RT = \033[0m

#                                 Print Function                               #

define print_libs
	@echo "${BABY_BLUE}====> ${1}${RT}"
endef

define print_status
	@echo "${LILAC}====> ${1}${RT}"
endef

define norm_check
	@echo "${AQUA}====> ${1}${RT}"
endef

#                                    Flag File                                 #

#COMPILATION_FLAG_FILE=.compilation_started

# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

SRCS = fractol.c \
	set_fractal/julia.c \
	set_fractal/mandelbrot.c \
	set_fractal/nova.c \
	set_fractal/tricorn.c \
	setup/color_setup.c \
	setup/events.c \
	setup/init_set.c \
	setup/mouse_event.c \
	setup/new_color.c \
	setup/render.c \
	setup/window.c \
	utils/art_intro.c \
	utils/check_args.c \
	utils/clean.c \
	utils/help_utils.c \
	utils/options.c \
	utils/utilis.c

OBJS = $(SRCS:.c=.o)


# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: Start $(NAME) End

Start :
	@if [ -f $(NAME) ]; then \
		echo "${LILAC}Checking if build is necessary...${RT}"; \
	else \
		echo "${PINK}Compiling Fract'ol...${RT}"; \
		echo "Starting the build process...!"; \
	fi

$(LIBFT):
	$(call print_libs,"Compiling Libft...")
	@make -C Libft > /dev/null
	@echo "${CHECK} Libft compiled                 ✅"

#Adding 2>&1 redirects both the standard output and standard error to /dev/null,
#thus suppressing all command line outputs, including those from ar.
$(LIB):
	$(call print_libs,"Building MLX...")
	@make -sC ../mlx > /dev/null 2>&1
	@echo "${CHECK} MLX compiled                 ✅"

$(NAME): $(OBJS) $(LIBFT) $(LIB)
	$(call print_status,"Creating Fractol...")
	@$(CC) $(INCLUDES) $(OBJS) $(LIBFT) $(LIB) $(MLXFLAGS) -o $@ > /dev/null
	@echo "${CHECK} Compiling utilities and grafics"

%.o: %.c
	@${CC} $(INCLUDES) ${CFLAGS} -c $< -o $@ > /dev/null

End :
	@echo "${PINK}Fract'ol...${RT}";
	@echo "${CHECK} successfully compiled!         🎉$(RT)";


# **************************************************************************** #
#                                clean RULES                                   #
# **************************************************************************** #

clean:
	@echo "${ORG}==> Cleaning up object files...${1}${RT}"
	@$(MAKE) clean -C Libft > /dev/null
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ../mlx > /dev/null
	@echo "${CHECK} Cleanup complete               🧹"

fclean: clean
	@echo "${ORG}==> Full clean - Removing executables...${1}${RT}"
	@$(MAKE) fclean -C Libft > /dev/null
	@$(RM) $(NAME)
	@echo "${CHECK} Full cleanup complete          🧹"

re: fclean all

.PHONY: all clean fclean re
