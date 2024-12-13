# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 13:19:59 by pkangas           #+#    #+#              #
#    Updated: 2024/08/17 13:25:07 by llitovuo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			 get_next_line.c get_next_line_utils.c
			
MY_OBJECTS = $(MY_SOURCES:.c=.o)

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

.PHONY: all re fclean clean bonus

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@ar -rcs $(NAME) $(MY_OBJECTS)
	@echo "\033[32;1m LIBFT Compilation successful!\033[0m"

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(MY_OBJECTS) $(BONUS_OBJ) .bonus

re: fclean all

bonus: .bonus

.bonus: $(BONUS_OBJ)
	@ar -rcs $(NAME) $(BONUS_OBJ)
	@touch .bonus
	@echo "\033[32;1mLIBFT BONUS Compilation successful!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
