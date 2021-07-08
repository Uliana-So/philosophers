CC		=	gcc

CFLAGS	= 	-g #-fsanitize=address #-Werror -Wall -Wextra

HEADER	=	./includes/

NAME	=	philo

SRC		=	./src/main.c ./src/check_argv.c \
			./src/print_message.c \
			./src/philo_lunch.c ./src/time.c \
			./lib/isdigit.c ./lib/atoi.c ./lib/strlen.c

OBJECTS	=	$(SRC:.c=.o)

all:        $(NAME) $(HEADER)

$(NAME): 	$(OBJECTS)
			@$(CC) $(CFLAGS) $(OBJECTS) -lpthread -o $(NAME)
			@echo ""
			@echo "\033[33m     ▂▃▅▇█▓▒░ DONE ░▒▓█▇▅▃▂\033[0m"
			@echo ""
	
%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@
			@echo "\033[35m   Compiling...  $<\033[0m"

clean:
			@rm -f $(OBJECTS)
			@echo "\033[32m------> CLEAN  completed <------\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[34m------> FCLEAN completed <------\033[0m"

re:			fclean all
			@echo "\033[36m------>   RE completed   <------\033[0m"

.PHONY:		all clean fclean re
