#include "main.h"

/**
 * print_hex - prints decimal in lowercase
 * @args: List of the arguments passed to the func
 * @params: para struct
 *
 * Return: Number of characters printed
 */

int print_hex(va_list args, params_t *params)
{
	unsigned long lc;
	int lw = 0;
	char *str;

	if (params->l_modifier)
		lc = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		lc = (unsigned short int)va_arg(args, unsigned int);
	else
		lc = (unsigned int)va_arg(args, unsigned int);

	str = convert(lc, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && lc)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (lw += print_number(str, params));
}

/**
 * print_HEX - prints decimal in lowercase
 * @args: List of the arguments passed to the func
 * @params: para struct
 *
 * Return: Number of characters printed
 */

int print_HEX(va_list args, params_t *params)
{
	unsigned long lc;
	int lw = 0;
	char *str;

	if (params->l_modifier)
		lc = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		lc = (unsigned short int)va_arg(args, unsigned int);
	else
		lc = (unsigned int)va_arg(args, unsigned int);

	str = convert(lc, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && lc)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (lw += print_number(str, params));
}

/**
 * print_binary - prints a binary number
 * @args: List of the arguments passed to the func
 * @params: para struct
 *
 * Return: Number of characters printed
 */

int print_binary(va_list args, params_t *params)
{
	unsigned int i = va_arg(args, unsigned int);
	char *str = convert(i, 2, CONVERT_UNSIGNED, params);
	int b = 0;

	if (params->hashtag_flag && i)
		*--str = '0';
	params->unsign = 1;
	return (b += print_number(str, params));
}

/**
 * print_octal - prints a number in octal notation
 * @args: List of the arguments passed to the func
 * @params: para struct
 *
 * Return: Number of characters printed
 */

int print_octal(va_list args, params_t *params)
{
	unsigned long num;
	char *str;
	int i = 0;

	if (params->l_modifier)
		num = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		num = (unsigned short int)va_arg(args, unsigned int);
	else
		num = (unsigned int)va_arg(args, unsigned int);
	str = convert(num, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (i += print_number(str, params));
}
