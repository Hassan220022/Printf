#include "main.h"

/**
* print_hex - Prints a representation of a decimal number on base16 lowercase
* @list: List of the arguments passed to the function
* Return: Number of characters printed
*/

int print_hex(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
