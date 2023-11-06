CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SOURCES = gauss_seidel.c
EXECUTABLE = linear_solver

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)

run:
	./$(EXECUTABLE)
