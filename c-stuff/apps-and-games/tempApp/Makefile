CC=gcc
src_dir=src
bin_dir=bin
util_dir=../../utility
app_name=tempApp

all : temp run

temp: $(src_dir)/tempApp.c
	$(CC) -Wall $(src_dir)/tempApp.c $(util_dir)/sorter.c $(util_dir)/utstring.c -o $(bin_dir)/temp

pretemp : %(src_dir)/tempApp.c
	$(CC) -E $(src_dir)/tempApp.c

run:
	./$(bin_dir)/temp 2>&1 | tee $(app_name).log

clean:
	rm $(bin_dir)/temp
