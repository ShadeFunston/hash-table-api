CC = gcc
CFLAGS = -Wall -std=c11 -g
BUILD = build/
BIN = bin/
SRC = src/
INC = include/
LDFLAGS = -L$(BIN)

hashtable: $(BIN)libhashtable.so

$(BIN)libhashtable.so: $(BUILD)HashTableAPI.o
	mkdir -p $(BIN) ;\
	$(CC) -shared -o $(BIN)libhashtable.so $(BUILD)HashTableAPI.o

$(BUILD)HashTableAPI.o: $(SRC)HashTableAPI.c $(INC)HashTableAPI.h
	mkdir -p $(BUILD) ;\
	$(CC) -I$(INC) $(CFLAGS) -c -fpic $(SRC)HashTableAPI.c -o $(BUILD)HashTableAPI.o

clean:
	rm -rf $(BUILD) $(BIN)