#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
void print_number(int n);
int print_decimal(va_list deci);
int print_binary(va_list args);
int print_hex(unsigned int no1, unsigned int lu);
int low_up(va_list lw);
int up_low(va_list up);
int print_unsigned(va_list args);
int print_oct(va_list args);


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
