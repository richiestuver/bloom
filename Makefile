sieve: sieve.c
	clang -std=c17 -Wall -Werror -Wextra -Wpedantic -lm -o sieve sieve.c

clean:
	rm -f sieve