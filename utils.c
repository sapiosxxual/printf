#include "main.h"
/**
 * is_printable - evaluation of characters if printable
 * @c: charcster to be printed
 * Return: 1 if c is printable, 0 if otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - it appends ascii in hexadecimal code to buffer
 * @buffer: Array of characters
 * @i: the start of appending
 * @ascii_code: the ASCII code
 * Return: Always (3)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexadeciaml fmt code is alwys 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - check if a character is a digit
 * @c: the char to be checked
 *
 * Return: 1 if digit 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' || c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - casting a num to a specific size
 * @num: the number
 * @size: number indicating the type to be casted
 *
 * Return: the casted value of the number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}

	return ((int)num);
}
/**
 * convert_size_unsgnd - casting a num to a specific size
 * @num: the number
 * @size: indicates the type to be casted
 * Return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
