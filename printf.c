#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	char *str;
	char ch;
	unsigned int u;
	void *p;

	setbuf(stdout, NULL);

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
					ch = (char)va_arg(args, int);
					count += _putchar(ch);
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						count += _putchar(*str);
						str++;
					}
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					count += _putchar((char)d);
					break;
				case 'u':
					u = va_arg(args, unsigned int);
					count += _putchar((char)u);
					break;
				case 'o':
					u = va_arg(args, unsigned int);
					count += _putchar((char)u);
					break;
				case 'x':
					u = va_arg(args, unsigned int);
					count += _putchar((char)u);
					break;
				case 'X':
					u = va_arg(args, unsigned int);
					count += _putchar((char)u);
					break;
				case 'p':
					p = va_arg(args, void *);
					count += _putchar((char)p);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return count;
}
