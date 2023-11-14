#include "main.h"

/**
 * print_char - Prints a character
 * @args: A list of arguments containing the character to print
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @args: A list of arguments containing the string to print
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len;

	if (str == NULL)
		str = "(null)";
	len = _puts(str);
	return (len);
}
