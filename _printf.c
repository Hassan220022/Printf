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
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'u':
				printf("%u", va_arg(args, unsigned int));
				break;
			case 'o':
				printf("%o", va_arg(args, unsigned int));
				break;
			case 'x':
				printf("%x", va_arg(args, unsigned int));
				break;
			case 'X':
				printf("%X", va_arg(args, unsigned int));
				break;
			case 'c':
				printf("%c", (char)va_arg(args, int));
				break;
			case 's':
				printf("%s", va_arg(args, char *));
				break;
			case 'p':
				printf("%p", va_arg(args, void *));
				break;
			// case '%':
			// 	putchar('%');
			// 	break;
			default:
				printf("%%%c", *format);
			}
			count++;
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return count;
}
