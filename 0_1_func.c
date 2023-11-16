#include "main.h"

/**
 * print_char - Prints a character
 * @args: A list of arguments
 * @params: para struct
 *
 * Return: The number of characters printed
 */
int print_char(va_list args, params_t *params)
{
	char rs = ' ';
	unsigned int a = 1, calc = 0, charc = va_arg(args, int);

	if (params->minus_flag)
		calc += _putchar(charc);
	while (a++ < params->width)
		calc += _putchar(rs);
	if (!params->minus_flag)
		calc += _putchar(charc);
	return (calc);
}

/**
 * print_int - Prints an integer
 * @args: A list of arguments
 * @params: para struct
 *
 * Return: The number of characters printed
 */

int print_int(va_list args, params_t *params)
{
	long i;

	if (params->l_modifier)
		i = va_arg(args, long);
	else if (params->h_modifier)
		i = (short int)va_arg(args, int);
	else
		i = (int)va_arg(args, int);
	return (print_number(convert(i, 10, 0, params), params));
}

/**
 * print_string - Prints a string
 * @args: A list containing the string to print
 * @params: para struct
 *
 * Return: The number of characters printed
 */

int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), rs = ' ';
	unsigned int a = 0, calc = 0, b = 0, i;

	(void) params;
	switch ((int) (!str))
		case 1:
			str = NULL_STRING;

	i = a = _strlen(str);
	if (params->precision < a)
		i = a = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (b = 0; b < a; b++)
				calc += _putchar(*str++);
		else
			calc += _puts(str);
	}
	while (i++ < params->width)
		calc += _putchar(rs);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (b = 0; b < a; b++)
				calc += _putchar(*str++);
		else
			calc += _puts(str);
	}
	return (calc);
}

/**
 * print_percent - prints a percent sign
 * @args: The name for va_list
 * @params: para struct
 *
 * Return: 1
 */

int print_percent(va_list args, params_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_String - Prints a string
 * @args: A list containing the string to print
 * @params: para struct
 *
 * Return: The number of characters printed
 */

int print_String(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *nv;
	int calc = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			calc += _putchar('\\');
			calc += _putchar('x');
			nv = convert(*str, 16, 0, params);
			if (!nv[1])
				calc += _putchar('0');
			calc += _puts(nv);
		}
		else
		{
			calc += _putchar(*str);
		}
	}
	return (calc);
}
