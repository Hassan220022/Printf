#include "main.h"
/**
* print_int - prints an integer
* @args: argument
* Return: number of digits printed
*/
int print_int(va_list args)
{
	int n = va_arg(args, int);

	unsigned int num;

	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}
	_putchar((num % 10) + '0');
	count++;

	return (count);
}
