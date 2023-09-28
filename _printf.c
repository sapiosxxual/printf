#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _putchar - write a char to stdout
 * @c: char to be printed
 * Return: On Success (1), On error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - function that produces output according to a format.
 * @format: the format string
 * Return: the no of chars printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format && format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += _print_str(va_arg(args, char *));
			else if (*format == '%')
				count += _putchar('%');
			else if (*format == 'd' || *format == 'i')
				count += _print_int(va_arg(args, int));
			else if (*format == 'b')
				count += _print_binary(va_arg(args, unsigned int));
			else
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
/**
 * _print_int - prints an integer
 * @n: integer to be printedd
 * Return: no of char printed
 */
int _print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	if (n / 10)
		count += _print_int(n / 10);
	_putchar((n % 10) + '0');
	count++;

	return (count);
}
/**
 * _print_str - print a string
 * @str: string to print
 * Return: no of char printed
 */
int _print_str(char *str)
{
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
/**
 * _print_binary - prints an integer in binary
 * @n: the integer
 * Return: the no of chars printed
 */
int _print_binary(unsigned int n)
{
	int count = 0;
	int binary[32];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		count++;
	}
	return (count);
}
