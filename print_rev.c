#include "main.h"

/**
* print_rev - prints a string in reverse
* @arg: argument to print in reversed
*
* Return: length of the printed string
*/

int print_rev(va_list arg)
{
	char *str = va_arg(arg, char *);

	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		len++;
		str++;
	}

	str--;

	while (len)
	{
		_putchar(*str);
		str--;
		len--;
	}

	return (len);
}
