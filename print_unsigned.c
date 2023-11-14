#include "main.h"

/**
 * print_unsigned - print an unsigned decimal integer
 * @args: argument
 * Return: unsigned decimal integer
 */

int print_unsigned(va_list args)
{
	unsigned int un = va_arg(args, unsigned int);
	int numero, a = un % 10, num, i = 1;

	un = un / 10;
	numero = un;

	if (numero > 0)
	{
		while (numero / 10 != 0)
		{
			i = i * 10;
			numero = numero / 10;
		}

		numero = un;

		while (i > 0)
		{
			num = numero / i;
			_putchar(num + '0');
			numero = numero - (num * i);
			i = i / 10;
			i++;
		}
	}

	_putchar(a + '0');

	return (i);
}
