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
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
