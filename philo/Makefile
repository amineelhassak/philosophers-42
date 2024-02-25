NAME = philo
SRCS = ./srcs/utile1.c ./srcs/utile2.c ./main.c ./srcs/utile3.c \
       ./srcs/utile4.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 
fclean: clean
	$(RM) $(NAME)

re: fclean all
