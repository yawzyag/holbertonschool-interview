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
	unsigned long num_add, num_rev = 0, start_num = n;

	while (start_num != 0)
	{
		num_add = start_num % 10;
		num_rev = num_rev * 10 + num_add;
		start_num = start_num / 10;
	}

	if (n == num_rev)
		return (1);
	return (0);
}
