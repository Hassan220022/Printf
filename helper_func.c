#include "main.h"

/**
 * print_from_to - print char address
 * @start: the start point
 * @stop: the end point
 * @except: the exclusion
 *
 * Return: void
*/

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - reverse the string
 * @args: the argument
 * @params: the parameter
 *
 * Return: void
*/

int print_rev(va_list args, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(args, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints in rot13
 * @args: the arguments
 * @params: the parameter structure
 *
 * Return: void
*/

int print_rot13(va_list args, params_t *params)
{
	int e, num;
	int calc = 0;
	char lett[] =
			"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *z = va_arg(args, char *);
	(void) params;

	e = 0;
	num = 0;
	while (z[e])
	{
		if ((z[e] >= 'A' && z[e] <= 'Z') ||
			(z[e] >= 'a' && z[e] <= 'z'))
		{
			num = z[e] - 65;
			calc += _putchar(lett[num]);
		}
		else
			calc += _putchar(z[e]);
		e++;
	}
	return (calc);
}
