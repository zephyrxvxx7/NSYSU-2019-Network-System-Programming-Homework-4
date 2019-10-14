compiler = gcc
obj = convert.o lookup1.o main.o

all: $(obj)
	$(compiler) -o convert convert.o
	$(compiler) -o file_lookup lookup1.o main.o

%.o: %.c
	$(compiler) -c $^ -o $@

.PHONY: clean
clean:
	rm *.o
