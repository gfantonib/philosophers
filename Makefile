NAME = philo
CC = cc
SRCPATH = source
INCPATH = include
HEADER = -I$(INCPATH)
OBJPATH = object
OBJ = $(patsubst %.c, $(OBJPATH)/%.o, $(SRC_FILES))
SRC_FILES = main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c | $(OBJPATH)
	$(CC) $(HEADER) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJ) $(OBJPATH)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean