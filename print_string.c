#include "main.h"

/**
 * print_string - Prints a string
 * @args: A va_list containing the string to print
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char*);

	int count = 0;

	for (int i = 0; s[i]; i++)
	{
		_putchar(s[i]);
		count++;
	}
	return (count);
}
