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

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
				_putchar(va_arg(args, int)), count++;
			else if (*format == 's')
				count += _print_str(va_arg(args, char *));
			else if (*format == '%')
				_putchar('%'), count++;
			else if (*format == 'd' || *format == 'i')
				count += _print_int(va_arg(args, int));
			else if (*format == 'b')
				count += _print_binary(va_arg(args, unsigned int));
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
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
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		num = -n;
		_putchar('-');
		count++;
	}
	else
	{
		num = n;
	}
	if (num / 10 != 0)
		count += _print_int(num / 10);
	_putchar((num % 10) + '0');
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
		_putchar('(');
		_print_str("null");
		_putchar(')');
		return (6);
	}

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
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
