#include "main.h"

/**
* print_decimal - function that prints an decimal
* @dec: the decimal
 *
* Return: Always 0
*/

int print_decimal(va_list args)
{
	int deci, a, j, digit, n, calc = 0, num;

	n = va_arg(args, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			calc++;
		}
		num = n;
		deci = 0;
		while (num != 0)
		{
			num /= 10;
			deci++;
		}
		a = 1;
		for (j = 1; j <= deci - 1; j++)
			a *= 10;
		for (j = 1; j <= deci; j++)
		{
			digit = n / a;
			if (n < 0)
				_putchar((digit * - 1) + 48);
			else
				_putchar(digit + '0');
			calc++;
			n -= digit * a;
			a /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (calc);
}
