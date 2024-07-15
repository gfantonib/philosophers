NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -pthread
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object
MAINOBJ = $(OBJPATH)/main.o
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)
SRCFILES = 01_check_valid_arg.c 02_store_data.c 03_init_philo.c 04_init_fork.c 05_create_thread.c 06_philo_routine.c 06_utils.c 07_footman_routine.c utils.c libft.c

all: $(NAME)

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAINOBJ) -o $(NAME)

$(OBJPATH)/main.o: main.c | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJ) $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

hel: all
	valgrind \
		--tool=helgrind \
		--history-level=none \
		-s \
		./$(NAME) 5 1800 200 200 

.PHONY: all clean fclean