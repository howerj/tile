#include <stdio.h>  /* Terrible Random Maze Generator */
#include <stdlib.h> /* Richard James Howe */
#include <time.h>   /* <mailto:howe.r.j.89@gmail.com> / <https://github.com/howerj/tile> */
/* The Unlicense / Public Domain */
int main(int argc, char **argv) { /* Usage: ./tile col row seed tiles... (all arguments optional) */
	static const char *s[] = { "\\ ", "/ ", "__", /* "  ", "| ", */ };
	const int C = argc > 1 ? atoi(argv[1]) : 40; /* could also use getenv or query terminal */
	const int r = argc > 2 ? atoi(argv[2]) : -1;
	const int c = C <= 0 ? 40 : C; /* default values could be specified with a #define */
	const int S = argc > 3 ? atoi(argv[3]) : time(NULL);
	const int l = argc > 4 ? argc - 4 : (int)(sizeof (s) / sizeof (s[0]));
	char **p = argc > 4 ? &argv[4] : (char**)s;
	srand(S < 0 ? time(NULL) : S);
	for (int i = 0, j = 0; r < 0 || j < r; i++) {
		if (fputs(p[rand() % l/*biased*/], stdout) < 0)
			return 1;
		if (i && !(i % c)) { if (putchar('\n') < 0) return 1; i = -1; j++; }
	}
	return 0;
}

