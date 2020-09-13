#include "palindrome.h"

/**
 * is_palindrome - check if unsigned long is a palindrome
 *
 * @n: unsigned to check
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long last, sum_rev = 0, i = n;

	while (i != 0)
	{
		last = i % 10;
		sum_rev = sum_rev * 10 + last;
		i = i / 10;
	}

	if (n == sum_rev)
		return (1);
	return (0);
}
