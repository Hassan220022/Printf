#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct print_t - struct for printing various types
 * @format: format specifier
 * @f: function pointer to print
 */
typedef struct print_t
{
	char *format;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);


print_t prints[] = {
	{'c', print_char},
	{'s', print_string},
     {'%', print_percent},
     /*{'d', print_int},
     {'i', print_int},
     {'b', print_binary},
     {'u', print_unsigned},
     {'o', print_octal},
     {'x', print_hex},
     {'X', print_HEX},
     {'p', print_address},*/
	{'\0', NULL}
};

#endif
