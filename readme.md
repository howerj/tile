# A Terrible Maze Generator

* Author: Richard James Howe
* License: The Unlicense / Public Domain
* Email: <mailto:howe.r.j.89@gmail.com>
* Repo: <https://github.com/howerj/tile>

Inspired by the tiny maze generation program for [Commodore 64 BASIC](https://en.wikipedia.org/wiki/Maze_generation_algorithm#Simple_algorithms):

	10 PRINT CHR$(205.5+RND(1)); : GOTO 10

This (**terrible**) maze generator does something similar, written in C. It is
only a few lines of C and is quite dense. The random number generator is
[biased](https://stackoverflow.com/questions/10984974/) (and the standard C
library functions used, `rand` is
[poor](https://stackoverflow.com/questions/52869166)), the maze is not
guaranteed to be solvable, and because of the characters used and available
it does not even looks as nice as the BASIC program does on the Commodore 64.

The use cases of this project are:

* To waste time.

If you find a use for this project (which could be replaced by a one
line shell script) then you need to reassess your life.

## USAGE

The program has multiple arguments, all of which are optional and are
entirely positional in nature.

	./tile columns rows seed tiles...

If no options are given then the program runs forever with the default
tile set, number of columns (really tiles which can be variable length
if specified) and a seed that comes from the current time.

You cannot specify a option without specifying all earlier options (so you
cannot specify `seed` without specifying both `columns` and `rows`). This makes
argument parsing trivial.

The default number of `columns` is 40 (as each tile in the default set is
2 chars wide this takes up 80 characters on screen before a newline is
printed). Set to a negative or zero value to keep the default.

The default number of `rows` is infinite. Set this to a negative value
to keep this (zero rows prints nothing).

The default seed is `time(NULL)`, set this to negative to keep this
default, otherwise specify zero or a positive integer as a seed.

The default tile set is `"\ "`, `"/ "`, and `"__"`. A random selection
of these tiles will be printed out.

## EXAMPLES

Infinite maze:

	./tile

Infinite maze (20 tiles wide):

	./tile 20

Maze 20 tiles wide, 20 rows deep (Long? Tall? Whatever):

	./tile 20 20

Reproducible mazes, which are just as important as reproducible
builds (20 tiles by 20 rows, seed is `1`...although the PRNG will
vary depending on your C library):

	./tile 40 40 1

**CUSTOM TILES**, what every user of `tile` has been waiting for, this new and
exciting feature has just dropped (20 tiles by 20 rows, seed is `1`):

	./tile 40 40 1 a b c

Same as above but seed is taken from `time(NULL)`:

	./tile 40 40 -1 a b c

An infinite wall of `a`, `b`, and you guessed it `c`, with a seed
chosen to suit your needs. All defaults used apart from the new
tile set:

	./tile -1 -1 -1 a b c


## RETURN VALUE

This program returns `1` on failure and `0` on success.

## THANKS

I would like to thank no one for this project. It took about 5 minutes.

## BUGS

If you find a bug, just keep it to yourself. No one cares. Go for a walk.

