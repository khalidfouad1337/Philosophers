SRCS		=   main.c init.c threads.c threads_utils.c utils.c		
OBJES 		=   ${SRCS:.c=.o}

NAME 		=   philo
CC 			=   cc
CFLAGS 		=   -Wall -Wextra -Werror
RM 			=   rm -rf

%.o		:	%.c
			$(CC) ${CFLAGS} -c $< -o $@
	

all		:	$(NAME)

$(NAME)	:	$(OBJES) 
			$(CC) $(FLAGS) $(OBJES) -o $(NAME)
 
clean	:
			$(RM) $(OBJES)

fclean	:	clean
			$(RM) $(NAME)

re		:	clean $(NAME)

run     : re

.PHONY	:	all clean fclean re