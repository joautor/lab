CC=gcc
src_dir=src
bin_dir=bin

all : snake

snake: $(src_dir)/snake.c
	$(CC) -pthread -o $(bin_dir)/snake $(src_dir)/snake.c

clean:
	rm $(bin_dir)/snake

run:
	./$(bin_dir)/snake
