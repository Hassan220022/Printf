#include "main.h"

/**
 * convert - the converter
 * @num: the number
 * @base: the base
 * @flags: the flags of the arguments
 * @params: the parameter
 *
 * Return: the converted
*/

char *convert(long int num, int base, int flags, params_t *params) {
	static char *uno;
	static char storage[50];
	char indicator = 0;
	char *ptr;
	unsigned long numero = num;
	(void) params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0) {
		numero = -num;
		indicator = '-';
	}
	uno = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &storage[49];
	*ptr = '\0';

	do {
		*--ptr = uno[numero % base];
		numero /= base;
	} while (numero != 0);

	if (indicator)
		*--ptr = indicator;
	return (ptr);
}

/**
 * print_unsigned - prints Unsigned integers
 * @args: the arguments
 * @params: the parameter
 *
 * Return: void
*/

int print_unsigned(va_list args, params_t *params)
{
	unsigned long ch;

	if (params->l_modifier)
		ch = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		ch = (unsigned short int)va_arg(args, unsigned int);
	else
		ch = (unsigned int)va_arg(args, int);
	params->unsign = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - print address
 * @args: the arguments
 * @params: the parameter
 *
 * Return: void
*/

int print_address(va_list args, params_t *params)
{
	unsigned long int ln = va_arg(args, unsigned long int);
	char *str;

	if (!ln)
		return (_puts("(nil)"));

	str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
