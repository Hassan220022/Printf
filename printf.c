#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
     int count = 0, d;
     char *str;
     char ch;
     unsigned int u;
     void *p;

     va_list args;

     va_start(args, format);

     while (*format != '\0')
     {
          if (*format == '%')
          {
               format++;
               switch (*format)
               {
               case 'c':
                    ch = va_arg(args, int);
                    _putchar(ch);
                    count++;
                    break;
               case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                         _putchar(*str);
                         str++;
                         count++;
                    }
                    break;
               case 'd':
               case 'i':
                    d = va_arg(args, int);
                    count += _putchar( d);
                    break;
               case 'u':
                    u = va_arg(args, unsigned int);
                    count += _putchar(u);
                    break;
               case 'o':
                    u = va_arg(args, unsigned int);
                    count += _putchar(u);
                    break;
               case 'x':
                    u = va_arg(args, unsigned int);
                    count += _putchar(u);
                    break;
               case 'X':
                    u = va_arg(args, unsigned int);
                    count += _putchar(u);
                    break;
               case 'p':
                    p = va_arg(args, void *);
                    count += _putchar(p);
                    break;
               case '%':
				   _putchar('%');
                    count++;
                    break;
               default:
				   _putchar('%');
				   _putchar(*format);
                    count += 2;
                    break;
               }
          }
          else
          {
               _putchar(*format);
               count++;
          }
          format++;
     }

     va_end(args);
     return (count);
}
