#include "main.h"

/**
 * get_precision - the precision affects how the value
 *     is displayed after the decimal point for float
 * @p: the string format
 * @args: the arguments
 * @params: the parameters
 *
 * Return: pointer
*/

char *get_precision(char *p, params_t *params, va_list args)
{
	int pre = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		pre = va_arg(args, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			pre = pre * 10 + (*p++ - '0');
	}
	params->precision = pre;
	return (p);
}
