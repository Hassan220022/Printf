#include "main.h"
/**
* _printf - Prints anything
* @format: A string containing all the desired characters
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{

	va_list args;
	va_start(args, format);

	unsigned int count = 0;

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			for (int j = 0; prints[j].format; j++)
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
