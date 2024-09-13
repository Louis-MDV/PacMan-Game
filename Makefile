# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 13:53:31 by lmerveil          #+#    #+#              #
#    Updated: 2024/03/14 14:03:29 by lmerveil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long
BNAME		=	so_long_bonus

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

SRCS		 = 	$(addsuffix .c,						\
				$(addprefix srcs/, 					\
					handle_keypress_core			\
					parse_keypress_core				\
					parsing_check_core				\
					parsing_check					\
					parsing_init_map_core			\
					parsing_utils					\
					player							\
					rendering						\
					set_struct_core					\
					set_img_core					\
					free_core						\
				)									\
				main								\
				)									\

BONUS		 = 	$(addsuffix .c,						\
				$(addprefix bonus/, 				\
					rendering_bonus					\
					parsing_check_bonus				\
					enemy							\
					main							\
					end_get_dir						\
				)									\
				$(addprefix srcs/,					\
					handle_keypress_core			\
					parse_keypress_core				\
					parsing_check_core				\
					parsing_check					\
					parsing_init_map_core			\
					parsing_utils					\
					player							\
					rendering						\
					set_img_core					\
					free_core						\
					set_struct_core					\
				)									\
				)									\

OFILES		= 	$(SRCS:.c=.o)
BOFILES 	= 	$(BONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "$(GREEN)[$(CC)]$(NC) compilation: $(YELLOW)$<$(NC)\r\c"

all: 	$(NAME)
bonus:	$(BNAME)
ball:	$(NAME) $(BNAME)

$(LIBFT_LIB):
	@make -sC $(LIBFT_PATH)
	@cp $(LIBFT_LIB) ./$(NAME)
	@echo "$(GREEN)[LIBFT Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(MLX_LIB):
	@make -sC $(MLX_PATH)
	@cp $(MLX_LIB) ./$(NAME)
	@echo "$(GREEN)[MLX Library]$(NC) copying to: $(YELLOW)$(NAME)$(NC)"

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OFILES)
	@$(CC) $(OFILES) $(MLX_LIB) $(MLXFLAGS) $(LIBFT_LIB) -o $(NAME) 
	@echo "$(GREEN)[EXECUTABLE]$(NC) created successfully: $(YELLOW)$(NAME)$(NC)"

$(BNAME): $(LIBFT_LIB) $(MLX_LIB) $(BOFILES)
	@$(CC) $(BOFILES) $(MLX_LIB) $(MLXFLAGS) $(LIBFT_LIB) -o $(BNAME)
	@echo "$(GREEN)[EXECUTABLE]$(NC) created successfully: $(YELLOW)$(BNAME)$(NC)"

.PHONY: all clean fclean re bonus

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -f $(OFILES) $(BOFILES)
	@echo "$(RED)[clean]$(NC) deleting OFILES: $(YELLOW)$(OFILES)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)[fclean]$(NC) deleting libraries: $(YELLOW)$(NAME) $(BNAME)$(LIBFT)$(NC)"

re: fclean all
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(NAME)$(NC)"

bre: fclean ball
	@echo "$(GREEN)[re]$(NC) rebuilding project: $(YELLOW)$(BNAME)$(NC)"
	
.PHONY: all clean fclean re bonus
