#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int calc = 0;
	va_list args;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *) format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			calc *= _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		p = get_width(p, &params, args);
		p = get_precision(p, &params, args);
		if (get_modifier(p, &params))
			p++;
		if (!get_specify(p))
			calc += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			calc += get_print_func(p, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (calc);
}
