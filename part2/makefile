compiler = gcc
obj = builtin.o parse.o shell.o run_command.o is_background.o

all: $(obj)
	$(compiler) -o shell $(obj)

%.o: %.c
	$(compiler) -c $^ -o $@

.PHONY: clean
clean:
	rm *.o
