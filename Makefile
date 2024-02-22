# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 13:53:31 by lmerveil          #+#    #+#              #
#    Updated: 2024/02/21 15:21:24 by lmerveil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long

CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror -g3
MLXFLAGS	= 	-L./minilibx-linux -lX11 -lXext -lXext -lmlx

RED			= 	$(shell tput setaf 1)
GREEN		= 	$(shell tput setaf 2)
YELLOW		= 	$(shell tput setaf 3)
NC			= 	$(shell tput sgr0)

LIBFT_PATH	=	./libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_PATH	=	./minilibx-linux
MLX_FILE	= 	libmlx.a
MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

SRCS		 = 	$(addsuffix .c,			\
				$(addprefix srcs/, 		\
				$(addprefix parsing_,	\
					check_input			\
					utils				\
					init_map			\
				))						\
				main					\
				)

OFILES		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "$(GREEN)[$(CC)]$(NC) compilation: $(YELLOW)$<$(NC)\r\c"

all: 	$(NAME)

$(LIBFT_LIB):
	make -sC $(LIBFT_PATH)
	@cp $(LIBFT_LIB) ./$(NAME)
	@echo "$(GREEN)[LIBFT Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(MLX_LIB):
	make -sC $(MLX_PATH)
	@cp $(MLX_LIB) ./$(NAME)
	@echo "$(GREEN)[MLX Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OFILES)
	@$(CC) $(OFILES) $(MLX_LIB) $(MLXFLAGS) $(LIBFT_LIB) -o $(NAME) 
	@echo "$(GREEN)[EXECUTABLE]$(NC) created successfully: $(YELLOW)$(NAME)$(NC)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -f $(OFILES)
	@echo "$(RED)[clean]$(NC) deleting OFILES: $(YELLOW)$(OFILES)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)[fclean]$(NC) deleting library: $(YELLOW)$(NAME)$(NC)"

re: fclean all
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(NAME)$(NC)"

.PHONY: all clean fclean re
