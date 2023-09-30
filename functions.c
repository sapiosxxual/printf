#include "main.h"
/**
 * print_unsgnd - prints unsigned integer
 * @n: the unsigned int
 * Return: no of chars printed
 */
int print_unsgnd(unsigned int n)
{
	char buffer[1024] = {0};
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
		count++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
	}
	return (count);
}
/**
 * print_octal - prints unsigned integer octal
 * @n: the unsigned integer
 * Return: mo of chars printed
 */
int print_octal(unsigned int n)
{
	char buffer[1024];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i] = (n % 8) + '0';
		n /= 8;
		i++;
		count++;
	}
	i--;

	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
	}
	return (count);
}
/**
 * print_hex - prints unsigned int in hexadecimal
 * @format: 'x' for lowercase, 'X' for uppercase
 * @n: the unsigned integer
 * Return: no of chars printe
 */
int print_hex(char format, unsigned int n)
{
	char buffer[1024];
	int i = 0;
	int count;
	char hex_chars[] = "0123456789ABCDEF";

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i] = hex_chars[n % 16];
		n /= 16;
		i++;
		count++;
	}
	i--;
	while (i >= 0)
	{
		if (format == 'x')
			buffer[i] = buffer[i] >= 'A' && buffer[i] <= 'F' ? buffer[i] + 32
				: buffer[i];
		_putchar(buffer[i]);
		i--;
	}
	return (count);
}
/**
 * print_S - prints a string with non printable char
 * @str: string to be printed
 * Return: no of chars printed
 */
int print_S(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count = print_hex('X', str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}
/**
 * print_pointer - print a memmory address in hexadecimal
 * @n: the memory address to be printed
 * Return: no of chars printed
 */
int print_pointer(unsigned int n)
{
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;
	count += print_hex('x', n);

	return (count);
}
