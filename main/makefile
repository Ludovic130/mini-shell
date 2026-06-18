# $(TARGET) <-- (i.e., mini-shell_v1).
# $(OBJS) <-- These are the dependencies (i.e., main.o utils.o others.o).
# $^ <-- Make automatic variable: meaning "All dependencies".
# $@ <-- Meaning "The name of the target".
# $(LDFLAGS) <-- the options (none here).
# $< <-- Meaning "The first dependency" (so the file X.c).

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

TARGET = mini-shell_v1.1
SRCS = main.c shell.c lex.c cmd.c m_history.c m_execvp.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET) # If the user types make all (or just make, since all is the first target),
               # then I must ensure that $(TARGET) (i.e., mini-shell_v1) exists.

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) -lreadline

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean