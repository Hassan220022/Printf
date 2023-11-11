#include "main.h"
/**
* print_int - prints an integer
* @args: argument
* Return: number of digits printed
*/
int print_int(va_list args)
{
	unsigned int i = va_arg(args, int);

	if (i < 0)
	{
		_putchar('-');
		i = -i;
	}
	if (i / 10)
	{
		print_int(i / 10);
	}
	_putchar(i % 10 + '0');
	return (i);
}
