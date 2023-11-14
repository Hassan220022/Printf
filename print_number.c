#include "main.h"

/**
 * print_int - prints an integer
 * @args: argument
 * Return: number of digits printed
 */
int print_int(va_list args)
{
	int len;

	len = print_number(args);
}

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */

int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9;)
		div *= 10;

	for (; div != 0;)
	{
		len += _putchar(int_to_char(num / div));
		num %= div;
		div /= 10;
	}

	return (len);
}
