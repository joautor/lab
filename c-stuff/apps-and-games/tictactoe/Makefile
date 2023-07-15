CC=gcc
src_dir=src
bin_dir=bin

all : tictactoe

tictactoe: $(src_dir)/tictactoe.c
	$(CC) -o $(bin_dir)/tictactoe $(src_dir)/tictactoe.c

clean:
	rm $(bin_dir)/tictactoe

run:
	./$(bin_dir)/tictactoe
