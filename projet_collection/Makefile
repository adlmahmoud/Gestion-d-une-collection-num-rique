# --- VARIABLES ---
CC = g++
CFLAGS = -Wall -Wextra -Iinc -g

OBJ = obj/main.o obj/collection.o obj/tri.o
EXEC = bin/collection

# --- REGLES ---
all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

obj/main.o: src/main.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o

obj/collection.o: src/collection.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/collection.cpp -o obj/collection.o

obj/tri.o: src/tri.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/tri.cpp -o obj/tri.o

clean:
	rm -f obj/*.o bin/*

run: all
	./$(EXEC)