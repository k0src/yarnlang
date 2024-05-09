exec = yarn.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

install:
	make
	cp ./yarn.out /usr/local/bin/yarn

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm stc/*.o