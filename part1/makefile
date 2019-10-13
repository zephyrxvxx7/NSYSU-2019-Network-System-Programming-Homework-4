compiler = gcc
obj = hostinfo.o mydate.o printdir.o mycat.o pipe_ls.o

all: $(obj)
	$(compiler) -o hostinfo hostinfo.o
	$(compiler) -o mydate mydate.o
	$(compiler) -o printdir printdir.o
	$(compiler) -o mycat mycat.o
	$(compiler) -o pipe_ls pipe_ls.o

%.o: %.c
	$(compiler) -c $^ -o $@

.PHONY: clean
clean:
	rm *.o
