#include "main.h"

/**
* print_hex_aux - prints an hexadecimal number.
* @num: arguments.
* Return: counter.
*/

int print_hex_aux(unsigned long int num)
{
	int count = 0;

	if (num / 16)
		count += print_hex_aux(num / 16);
	if (num % 16 < 10)
		count += _putchar((num % 16) + '0');
	else
		count += _putchar((num % 16) - 10 + 'a');
	return (count);
}
