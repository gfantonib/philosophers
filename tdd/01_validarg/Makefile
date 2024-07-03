NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o) #$(patsubst %.c, $(OBJPATH)/%.o, $(SRCFILES))
SRCFILES = 01_check_valid_arg.c utils.c
MAINOBJ = main.o

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
	$(CC) $(OBJ) $(MAINOBJ) -o $(NAME)
	rm -f $(MAINOBJ)

$(MAINOBJ): main.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.c | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJ) $(OBJPATH)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean