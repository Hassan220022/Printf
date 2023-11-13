#include "main.h"

/**
* _printf - Prints anything
* @format: A string containing all the desired characters
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
	print_t prints[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{0, NULL}
	};
	unsigned int count = 0;

	unsigned int i, j;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i]; i++)

	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			for (j = 0; prints[j].format; j++)

			{
				if (prints[j].format == format[i])
				{
					count += prints[j].f(args);
					break;
				}
			}
		}
	}

	va_end(args);
	return (count);
}
