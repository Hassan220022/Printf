#include "main.h"

/**
 * _isdigit - check if it is a digit
 * @c: the character
 *
 * Return: 1 if success, else 0
*/

int _isdigit(int c)
{
	return ( c >= '0' && c <= '9');
}

/**
 * _strlen - length of the string
 * @s: the string
 *
 * Return: the length
*/

int _strlen(char *s)
{
	int ln = 0;

	while (*s++)
		ln++;
	return (ln);
}

/**
 * print_number - print number
 * @str: the base
 * @params: the parameter
 *
 * Return: the character
*/

int print_number(char *str, params_t *params)
{
	unsigned int a = _strlen(str);
	int num = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (num)
	{
		str++;
		a--;
	}
	if (params->precision != UINT_MAX)
		while (a++ < params->precision)
			*--str = '0';
	if (num)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_side(str, params));
	else
		return (print_number_left_side(str, params));
}

/**
 * print_number_right_side - print number
 * @str: the base
 * @params: the parameter
 *
 * Return: the character
*/

int print_number_right_side(char *str, params_t *params)
{
	unsigned int n = 0, num1, num2, a = _strlen(str);
	char rs = ' ';

	if (params->zero_flag && !params->minus_flag)
		rs = '0';
	num1 = num2 = (!params->unsign && *str == '-');
	if (num1 && a < params->width && rs == '0' && !params->minus_flag)
		str++;
	else
		num1 = 0;

	if ((params->plus_flag && !num2) ||
			(!params->plus_flag && params->space_flag && !num2))
		a++;
	if (num1 && rs == '0')
		n += _putchar('-');
	if (params->plus_flag && !num2 && rs == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !num2 &&
	!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (a++ < params->width)
		n+= _putchar(rs);
	if (num1 && rs == ' ')
		n += _putchar('-');
	if (params->plus_flag && !num2 && rs == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !num2 &&
	!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_side - print number
 * @str: the base
 * @params: the parameter
 *
 * Return: the character
*/

int print_number_left_side(char *str, params_t *params)
{
	unsigned int n = 0, num1, num2, a = _strlen(str);
	char rs = ' ';

	if (params->zero_flag && !params->minus_flag)
		rs = '0';
	num1 = num2 = (!params->unsign && *str == '-');
	if (num1 && a < params->width && rs == '0' && !params->minus_flag)
		str++;
	else
		num1 = 0;

	if (params->plus_flag && !num2 && !params->unsign)
		n += _putchar('+'), a++;
	else if (params->space_flag && !num2 && params->unsign)
		n += _putchar(' '), a++;
	n += _puts(str);
	while (a++ < params->width)
		n += _putchar(rs);
	return (n);
}
