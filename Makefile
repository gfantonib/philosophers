NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object
MAINOBJ = $(OBJPATH)/main.o
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o)
SRCFILES = 01_check_valid_arg.c 02_store_data.c 03_init_philo.c 04_init_fork.c utils.c

all: $(NAME)

$(NAME): $(MAINOBJ) $(OBJ)
	$(CC) $(OBJ) $(MAINOBJ) -o $(NAME)

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

.PHONY: all clean fclean