run: snake
	./snake
snake: snake.c
	indent snake.c
	cc snake.c -l curses -o snake
clean:
	rm snake *.BAK
