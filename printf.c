#include <stdio.h>
#include "main.h"

/**
<<<<<<< HEAD
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
=======
 * _printf - Custom printf function
 *
 * @format: Format string
 *
 * Return: Number of characters printed
*/

int _printf(const char *format, ...)
{
	int count = 0;
	int d;
	char *str;
	char ch;
	unsigned int u;
	void *p;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					count += printf("%d", d);
					break;
				case 'u':
					u = va_arg(args, unsigned int);
					count += printf("%u", u);
					break;
				case 'o':
					u = va_arg(args, unsigned int);
					count += printf("%o", u);
					break;
				case 'x':
					u = va_arg(args, unsigned int);
					count += printf("%x", u);
					break;
				case 'X':
					u = va_arg(args, unsigned int);
					count += printf("%X", u);
					break;
				case 'p':
					p = va_arg(args, void *);
					count += printf("%p", p);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
>>>>>>> refs/remotes/origin/main
}
