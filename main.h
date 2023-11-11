#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);


/**
* struct print_t - struct for printing various types
* @format: format specifier
* @f: function pointer to print
*/
typedef struct print_t
{
	char format;

	int (*f)(va_list);
} print_t;



#endif
