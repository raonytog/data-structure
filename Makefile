run:
	clear
	gcc -o prog *.c 
	./prog

valgrind:
	clear
	gcc -o prog *.c 
	valgrind --leak-check=full --show-leak-kinds=all -s ./prog