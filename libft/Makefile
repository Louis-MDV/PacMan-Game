# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:33:24 by louismdv          #+#    #+#              #
#    Updated: 2024/02/28 16:28:44 by lmerveil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Fichiers .c
SOURCES = ft_atoi.c					\
		 ft_strrchr.c				\
		 ft_bzero.c					\
		 ft_calloc.c				\
		 ft_isalnum.c				\
		 ft_isalpha.c				\
		 ft_isascii.c				\
		 ft_isdigit.c				\
		 ft_isprint.c				\
		 ft_memchr.c				\
		 ft_memcmp.c				\
		 ft_memcpy.c				\
		 ft_memmove.c				\
		 ft_memset.c				\
		 ft_strchr.c				\
		 ft_strdup.c				\
		 ft_strlcat.c				\
		 ft_strlcpy.c				\
		 ft_strlen.c				\
		 ft_strncmp.c				\
		 ft_strnstr.c				\
		 ft_tolower.c				\
		 ft_toupper.c				\
		 ft_striteri.c				\
		 ft_putnbr_fd.c				\
		 ft_putendl_fd.c			\
		 ft_putstr_fd.c				\
		 ft_putchar_fd.c			\
		 ft_strmapi.c				\
		 ft_split.c					\
		 ft_itoa.c					\
		 ft_substr.c				\
		 ft_strtrim.c				\
		 ft_strjoin.c				\
		 get_next_line_utils.c		\
		 get_next_line.c			\
		 print_c.c					\
		 print_id.c					\
		 print_p.c					\
		 print_s.c					\
		 print_u.c					\
		 print_xx.c					\
		 print.c					\
# Convertit les noms de fichiers .c en .o
OBJ = $(SOURCES:.c=.o)

BONUS = ft_lstnew.c					\
		ft_lstsize.c				\
		ft_lstadd_front.c			\
		ft_lstlast.c				\
		ft_lstadd_back.c			\
		ft_lstiter.c				\
		ft_lstclear.c				\
		ft_lstdelone.c				\
		ft_lstmap.c					\

BOBJ = $(BONUS:.c=.o)

# Définit le compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -I.

# Nom de l'archive à créer
NAME = libft.a

# Règle par défaut
all: $(NAME)

# Créer l'archive à partir des fichiers .o
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Règle de compilation des fichiers sources en fichiers objets
.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

# Nettoie les fichiers compilés et l'archive
clean:
	rm -f $(OBJ) $(BOBJ)

fclean:
	rm -f $(OBJ) $(NAME) $(BOBJ)

re: clean all

# Règle pour éviter les conflits de noms entre un fichier et une règle
.PHONY: all clean flcean re bonus
