#include "main.h"

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	int num;

	print_t bor3i[] = {
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_String},
		{"r", print_rev},
	};
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	num = parser(format, bor3i, args);
	va_end(args);
	return (num);
}
