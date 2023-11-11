#include "main.h"

/**
* print_char - Prints a character
* @args: A list of arguments containing the character to print
* Return: The number of characters printed
*/
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
