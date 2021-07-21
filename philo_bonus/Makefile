CC		=	gcc

CFLAGS	= 	-Wall -Wextra -Werror

OBJDIR	=	objs
SRCDIR	=	src

NAME	=	philo_bonus

SRC		=	main.c \
			time.c \
			check_argv.c \
			print_message.c \
			philo_lunch.c \
			philo_utils.c

SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ		=	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)
			@echo ""
			@echo "\033[33m     ▂▃▅▇█▓▒░ DONE (BONUS) ░▒▓█▇▅▃▂\033[0m"
			@echo ""

$(OBJ):		|$(OBJDIR)

$(OBJDIR):
			@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c ./includes/philo_header.h
			@$(CC) $(CFLAGS) -I ./includes -c $< -o $@
			@echo "\033[35m      Compiling...  $<\033[0m"

clean:
			@rm -rf $(OBJDIR)
			@echo "\033[32m------> CLEAN  completed <------\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[34m------> FCLEAN completed <------\033[0m"

re:			fclean all
			@echo "\033[36m------>   RE completed   <------\033[0m"

.PHONY:		all clean fclean re