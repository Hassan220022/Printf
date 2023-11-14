#include "main.h"
/**
* print_hex - prints a hexadecimal
* @no1: var1
* @lu: printing lower and upper case
 *
* Return: size the output
*/

int print_hex(unsigned int no1, unsigned int lu)
{
	int calc = 0;
	char separate;
	unsigned int num1, num2;
	unsigned int i, nom, num;


	if (no1 != 0)
	{
		num = no1;
		num1 = 0;
		if (lu)
			separate = 'A' - ':';
		else
			separate = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			num1++;
		}
		num2 = 1;
		for (i = 1; i <= num1 - 1; i++)
			num2 *= 16;
		for (i = 1; i <= num1; i++)
		{
			nom = no1 / num2;
			if (nom < 10)
				_putchar(nom + '0');
			else
				_putchar(nom + '0' + separate);
			calc++;
			no1 -= nom * num2;
			num2 /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (calc);
}

/**
* low_up - print in lowercase
* @lw: the int that is going to be printed
*
* Return: an output size
*/

int low_up(va_list lw)
{
	return (print_hex(va_arg(lw, unsigned int), 0));
}

/**
* up_low - print in uppercase
* @lw: the int that is going to be printed
*
* Return: an output size
*/

int up_low(va_list up)
{
	return (print_hex(va_arg(up, unsigned int), 1));
}
