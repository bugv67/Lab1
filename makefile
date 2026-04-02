all:
	gcc -m32 -g -Wall hello.c -o hello

clean:
	rm -f hello