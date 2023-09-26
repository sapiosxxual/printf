#include "main.h"
/* print pointer */
/**
 * print_pointer - prints the value of a pointer variable
 * @types: the argument list
 * @buffer: buffer array to handle the print
 * @flags: calculates the active flags
 * @width: get the width
 * @precision: specification of precision
 * @size: sepcifier of size
 * Return: the number of characters printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int
		precision, int size)
{
	char extra_ch = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/* length = 2, for '0,' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
	{
		extra_ch = '+';
		length++;
	}
	else if (flags & F_SPACE)
	{
		extra_ch = ' ';
		length++;
	}
	ind++;
	/* return (write(1, &buffer[i], BUFF_SIZE - i - 1)); */
	return (write_pointer(buffer, ind, length, width, flags, padd, extra_ch,
				padd_start));
}
/**
 * print_non_printable - prints ascii code in hexadecim of nonprintable chars
 * @types: argument list
 * @buffer: buffer array to handle printf function
 * @flags: calc the active flags
 * @precision: specification of precision
 * @size: specifying the size
 * @width: the width
 * Return: number of characters printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - prints  string in reveree
 * @types: list of the arguments
 * @buffer: buffer array that handles the print
 * @size: specified size
 * @precision: specification of precision
 * @flags: calc active flags
 * @width: the width
 * Return: number of charcaters printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int size,
		int precision)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")NULL(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - printing string in rot13
 * @types: the list of the arguments
 * @buffer: buffer array to handle print
 * @flags: calc the active flags
 * @size: specified size
 * @precision: specification of size
 * @width: getting the width
 * Return: number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int
		precision, int size)
{
	char x, *str;
	int count = 0;
	unsigned int i, j;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "AHYY";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}

	}
	return (count);
}
