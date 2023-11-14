#include "main.h"

/**
 * print_oct - print octal numbers.
 * @args: arguments.
 * Return: octal number.
 */

int print_oct(va_list args)
{
	int ok;
	int *oct;
	int calc = 0;
	unsigned int num1 = va_arg(args, unsigned int);
	unsigned int numero = num1;

	while (num1 / 8 != 0)
	{
		num1 /= 8;
		calc++;
	}
	calc++;
	oct = malloc(calc * sizeof(int));

	for (ok = 0; ok < calc; ok++)
	{
		oct[ok] = numero % 8;
		numero /= 8;
	}
	for (ok = calc - 1; ok >= 0; ok--)
	{
		_putchar(oct[ok] + '0');
	}
	free(oct);
	return (calc);
}
