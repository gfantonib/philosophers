NAME = philo
CC = cc
SRCDIR = source
INCDIR = include
OBJDIR = object
SRC_FILES = main.c
HEADER = -I$(INCDIR)

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_FILES))

# Default target
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Pattern rule to create object files in the objects directory
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(HEADER) -c $< -o $@

# Ensure the objects directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule
clean:
	rm -f $(OBJ) $(NAME)
	rm -rf $(OBJDIR)

# Phony targets
.PHONY: all clean