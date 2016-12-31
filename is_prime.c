/*
 * 2017 is a prime year; I wanted to check that.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define USAGE "USAGE: %s n, where n is positive"

bool prime (long n) {
	assert (n > 0);
	if (1 == n) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	long limit = sqrt(n) + 1;
	for (long factor = 3; factor < limit; factor += 2) {
		if (n % factor == 0) {
			return false;
		}
	}
	return true;
}

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
	if (1 == n) {
		printf ("1 is not prime\n");
		return EXIT_SUCCESS;
	}
	if (n <= 3) {
		printf ("%ld is prime\n", n);
		return EXIT_SUCCESS;
	}
	long limit = sqrt(n) + 1;
	long factor = 2;
	bool is_prime = true;
	bool we_already_said_divisible_by = false;
	if (n % factor == 0) {
		printf ("%ld is divisible by 2", n);
		is_prime = false;
		we_already_said_divisible_by = true;
	}
	for (factor = 3; factor <= limit && prime(factor); factor += 2) {
		if (n % factor == 0) {
			if (we_already_said_divisible_by) {
				printf (" %ld", factor);
			}
			else {
				printf ("%ld is divisible by %ld", n, factor);
				we_already_said_divisible_by = true;
			}
			is_prime = false;
		}
	}
	if (is_prime) {
		printf ("%ld is prime", n);
	}
	printf ("\n");
	return EXIT_SUCCESS;
}

