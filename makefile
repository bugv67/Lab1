all:part0 part1 part2

CFLAGS= -m32 -g -Wall  # -DDEBUG FLAGS

part0: count-words.c
	gcc $(CFLAGS) count-words.c -o part0

part1: addresses.c
	gcc $(CFLAGS) addresses.c -o part1

part2.o: base.c
	gcc -m32 -g -Wall -c -o part2.o base.c
part2: part2.o
	gcc -g -m32 -Wall -o part2 part2.o

clean:
	rm -f part0 part1 part2




	