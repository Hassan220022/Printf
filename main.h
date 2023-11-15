#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters structure
 *
 * @unsign: unsigned values
 *
 * @plus_flag: use if plus_flag is required
 * @space_flag: use if hashtag_flag is required
 * @hashtag_flag: use if _flag is required
 * @zero_flag: use it if _flag is required
 * @minus_flag: use it if _flag is required
 *
 * @width: the width
 * @precision: the precision
 *
 * @h_modifier: use it if h_modifier is needed
 * @l_modifier: use it if l_modifier is needed
 */

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width : 1;
	unsigned int precision : 1;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specify - struct for printing various types
 *
 * @specify: format specifier
 * @f: function pointer to print
 */

typedef struct specify
{
	char *specify;

	int (*f)(va_list, params_t *);
} specify_t;

int _putchar(char c);
int _puts(char *str);

int _printf(const char *format, ...);

/* task 0 & 1*/
int print_char(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_String(va_list args, params_t *params);

/* adv */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);

/* helpers */
int (*get_specify(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* adv 2 */
int print_binary(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);

/* adv 3 */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);

/* helpers 2*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_side(char *str, params_t *params);
int print_number_left_side(char *str, params_t *params);

char *get_precision(char *p, params_t *params, va_list args);

/* int parameters */
void init_params(params_t *params, va_list args);

#endif
