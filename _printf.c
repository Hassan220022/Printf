#include "main.h"

/**
* _printf - prints anything
* @format: list of argument types passed to the function
*
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int num_chars = 0;

	int i, j;

	print formats[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
	};

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < sizeof(formats) / sizeof(formats[0]); j++)
			{
				if (format[i + 1] == *(formats[j].format))
				{
					num_chars += formats[j].f(args);
					break;
				}
			}
			i++;
		}
		else
		{
			putchar(format[i]);
			num_chars++;
		}
	}

	va_end(args);

	return (num_chars);
}


int print_char(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);
	return (1); // Return the number of characters printed
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	int len = 0;

	while (*str != '\0')
	{
		putchar(*str);
		str++;
		len++;
	}

	return (len);
}

int print_percent(__attribute__((unused)) va_list args)
{
	putchar('%');
	return (1); // Return the number of characters printed
}
