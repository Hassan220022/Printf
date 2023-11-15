#include "main.h"

/**
* _putchar - Writes a character to the standard output (stdout).
* @c: The character to write.
*
* Return: If successful, the character written. Otherwise, -1.
*/

int _putchar(char c)
{
	static int ne;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || ne >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, ne);
		ne = 0;
	}
	if (c != BUF_FLUSH)
		buf[ne++] = c;
	return (1);
}

/**
 * _puts - Prints a string to the standard output (stdout).
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */

int _puts(char *str)
{
	char *n = str;

	while (*str)
		_putchar(*str++);
	return (str - n);
}
