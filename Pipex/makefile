NAME		= pipex

OBJS		= ${SRCS:.c=.o}
SRC			=  main.c free.c error.c utils.c ft_split.c
SRCS		= ${addprefix src/, ${SRC}}
CC+FLAGS 	= gcc -Wall -Wextra -Werror -g

HEADER		= pipex.h

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@printf "Compiling [%s]...%-42s${RESET}\r" $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\nFinished : $(NAME)${RESET}"

all:	${NAME}

clean:
		@rm -rf ${OBJS}
		@echo "Removing objects...${RESET}"

fclean:	clean
		@rm -rf ${NAME}
		@echo "Removing ${NAME}...${RESET}"

re:		fclean all

.PHONY : all clean fclean re