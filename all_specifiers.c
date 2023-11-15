#include "main.h"

/**
 * get_specify - get the specifiers for our function
 * @s: formatted string of characters
 *
 * Return: Always 0
 */

int (*get_specify(char *s))(va_list args, params_t *params)
{
	specify_t all[] = {
			{"c", print_char},
			{"d", print_int},
			{"%", print_percent},
			{"s", print_string},
			{"i", print_int},
			{"b", print_binary},
			{"o", print_octal},
			{"u", print_unsigned},
			{"x", print_hex},
			{"X", print_HEX},
			{"p", print_address},
			{"S", print_String},
			{"r", print_rev},
			{"R", print_rot13},
			{NULL, NULL},
		};
	int seen = 0;

	while (all[seen].specify)
	{
		if (*s == all[seen].specify[0])
		{
			return (all[seen].f);
		}
		seen++;
	}
	return (NULL);
}

/**
 * get_print_func - determine the right format
 * @s: the string format
 * @args: the arguments
 * @params: the parameters
 *
 * Return: the bytes number
 */

int get_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specify(s);

	if (f)
		return (f(args, params));
	return (0);
}

/**
 * get_flag - flag function
 * @s: the string format
 * @params: the parameters
 *
 * Return: void
 */

int get_flag(char *s, params_t *params)
{
	int fl = 0;

	switch (*s)
	{
	case '+':
		fl = params->plus_flag = 1;
		break;
	case ' ':
		fl = params->space_flag = 1;
		break;
	case '#':
		fl = params->hashtag_flag = 1;
		break;
	case '-':
		fl = params->minus_flag = 1;
		break;
	case '0':
		fl = params->zero_flag = 1;
		break;
	}
	return (fl);
}

/**
 * get_modifier - the modifier function
 * @s: the string format
 * @params: the parameters
 *
 * Return: void
 */

int get_modifier(char *s, params_t *params)
{
	int mod = 0;

	switch (*s)
	{
	case 'h':
		mod = params->h_modifier = 1;
		break;
	case 'l':
		mod = params->l_modifier = 1;
		break;
	}
	return (mod);
}

/**
 * get_width - note the width of the formatted string
 * @s: the string format
 * @args: the arguments
 * @params: the parameters
 *
 * Return: pointer
 */

char *get_width(char *s, params_t *params, va_list args)
{
	int wide = 0;

	if (*s == '*')
	{
		wide = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			wide = wide * 10 + (*s++ - '0');
	}
	params->width = wide;
	return (s);
}
