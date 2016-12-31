#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define USAGE "USAGE: %s n, where n is positive"

int main(int argc, char ** argv) {
	long n = 0;
	switch (argc) {
		case 2:
			n = strtol(argv[1], NULL, 0);
			break;
		default:
			printf (USAGE "\n", argv[0]);
			return EXIT_FAILURE;
			break;
	}
	if (n <= 0) {
		printf (USAGE "\n", argv[0]);
		return EXIT_FAILURE;
	}
	if (n == 1) {
		printf ("1 is not prime\n");
		return EXIT_SUCCESS;
	}
	if (n < 3) {
		printf ("%ld is prime\n", n);
		return EXIT_SUCCESS;
	}
	long limit = sqrt(n);
	if (n % 2 == 0) {
		printf ("%ld is divisible by 2\n", n);
	}
	else {
		long factor;
		for (factor = 3; factor <= limit; factor += 2) {
			if (n % factor == 0) {
				printf ("%ld is divisible by %ld\n", n, factor);
				break;
			}
		}
		if (factor > limit) {
			printf ("%ld is prime\n", n);
		}
	}
	return EXIT_SUCCESS;
}

