#include <stdlib.h>
#include <unistd.h>
#include <curses.h>


int
main()
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	enum dir {
		L, R, U, D
	};
	int		len = 1920;
	char		sc[len];
	int		pos = len / 2;
	int		prev = pos;
	enum dir	d = R;
	for (int i = 0; i < len; i++) {
		if (i % 175 == 0)
			sc[i] = 'X';
		else
			sc[i] = ' ';
	}
	while (1) {
		sc[prev] = ' ';
		sc[pos] = '*';
		prev = pos;
		system("clear");
		write(1, sc, len);
		switch (getch()) {
		case 'j':
			d = L;
			break;
		case 'i':
			d = U;
			break;
		case 'k':
			d = D;
			break;
		case 'l':
			d = R;
			break;
		}
		switch (d) {
		case L:
			pos -= 1;
			if (pos / 80 != prev / 80)
				pos += 80;
			break;
		case R:

			pos += 1;
			if (pos / 80 != prev / 80)
				pos -= 80;
			break;
		case U:
			pos -= 80;
			if (pos < 0) {
				pos = len - 80 + prev;
			}
			break;
		case D:
			pos += 80;
			break;
		}
		pos = pos % len;
		fflush(stdout);
		usleep(100000);
	};
}
