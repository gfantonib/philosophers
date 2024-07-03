NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object
OBJ = $(SRCFILES:%.c=$(OBJPATH)/%.o) #$(patsubst %.c, $(OBJPATH)/%.o, $(SRCFILES))
SRCFILES = main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c | $(OBJPATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJ) $(OBJPATH)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean