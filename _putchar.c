#include "main.h"
/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to write.
 *
 * Return: If successful, the character written. Otherwise, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to the standard output (stdout).
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
