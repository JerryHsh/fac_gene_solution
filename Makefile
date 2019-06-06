main: 
	gcc -c *.c
	gcc *.o -o test

clean: 
	rm *.o
