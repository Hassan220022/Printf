#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>

/**
 * struct print_t - struct for printing various types
 * @format: format specifier
 * @f: function pointer to print
 */
typedef struct print_t
{
	char *format;

	int (*f)(va_list);
} print;

int _putchar(char c);
int _printf(const char *format, ...);


#endif
