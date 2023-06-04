SHELL		=	/bin/bash

NAME		= client
NAMESV		= server
LIBFT		= libft
INC		= inc
HEADER		= -I inc
SRC_DIR		= src/
OBJ_DIR		= obj/
CC		= gcc
FLAGS		= -Wall -Werror -Wextra
FSANITIZE	= -fsanitize=address -g3
RM		= rm -f
ECHO		= echo -e

PRINTF_PATH = ./ft_printf/
PRINTF_FILE = libftprintf.a

FTPRINTF_PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))


SRCCL_FILES	=	client
SRCSV_FILES	=	server

SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

OBJF		=	.cache_exists

start:
			@make -C $(LIBFT)
			@make -C $(PRINTF_PATH)
			@cp $(LIBFT)/libft.a .
			@make all

all:		$(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			@$(CC) $(FLAGS) $(OBJCL) $(FTPRINTF_PRINTF) $(HEADER) libft.a -o $(NAME)
			@make -sC $(PRINTF_PATH)

$(NAMESV):	$(OBJSV) $(OBJF)
			@$(CC) $(FLAGS) $(OBJSV) $(FTPRINTF_PRINTF)  $(HEADER) libft.a -o $(NAMESV)
			@make -sC $(PRINTF_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@make clean -sC $(PRINTF_PATH)

fclean:		clean
			@$(RM) $(NAME) $(NAMESV)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			make fclean -sC $(PRINTF_PATH)

re:			fclean all

.PHONY:		start all clean fclean re bonus norm

