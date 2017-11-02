all: stat.c
	gcc -o stat_info stat.c

clean:
	rm stat_info
	rm *~

run: all
	./stat_info
