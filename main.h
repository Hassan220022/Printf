#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>


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

int _printf(const char *format, ...);
int format_reciever(const char *format, print_t bo3i[], va_list args);
int _putchar(char c);
int _puts(char *str);
int print_int(va_list b);
int print_number(va_list args);
int print_percent(__attribute__((unused)) va_list args);
int print_unsigned_integer(va_list list);
int print_unsgined_number(unsigned int n);
int print_char(va_list args);
int print_string(va_list args);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_String(va_list args);
int print_rev(va_list arg);
int print_hex_aux(unsigned long int num);



#endif
