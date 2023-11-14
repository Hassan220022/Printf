#include "main.h"

/**
* print_binary - binary
* @b: binary digit
 *
* Return: Always 0
*/

int print_binary(va_list args)
{
	unsigned int bin, a, i, num1, n, num;
	int calc = 0;

	n = va_arg(args, unsigned int);
	if (n != 0)
	{
		num = n;
		bin = 0;
		while (num != 0)
		{
			num /= 2;
			bin++;
		}
		a = 1;
		for (i = 1; i <= bin - 1; i++)
			a *= 2;
		for (i = 1; i <= bin; i++)
		{
			num1 = n / a;
			_putchar(num1 + '0');
			calc++;
			n -= num1 * a;
			a /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (calc);
}
