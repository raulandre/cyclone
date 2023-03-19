CC=clang++
CFLAGS=-std=c++17 -g
LFLAGS=-lm -lraylib -ldl -pthread
INCLUDE=-Iinclude/
OUT=test

all: src/*.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LFLAGS) -o $(OUT)

clean:
	rm $(OUT)
