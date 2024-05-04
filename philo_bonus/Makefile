NAMEB = philo_bonus
SRCSB = ./srcs_bonus/utile1_bonus.c ./srcs_bonus/utile2_bonus.c ./srcs_bonus/utile3_bonus.c \
		 ./srcs_bonus/utile4_bonus.c ./main.c
OBJSB = $(SRCSB:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f

all: $(NAMEB)

$(NAMEB): $(OBJSB)
	@$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB)

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSB)

fclean: clean
	$(RM) $(NAMEB)

re: fclean all
