#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: format string
 * 
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;
    char ch;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
/*
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
                case 'u':
                    count += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += printf("%o", va_arg(args, unsigned int));
                    break;
                case 'x':
                    count += printf("%x", va_arg(args, unsigned int));
                    break;
                case 'X':
                    count += printf("%X", va_arg(args, unsigned int));
                    break;
                case 'p':
                    count += printf("%p", va_arg(args, void *));
                    break;*/
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
