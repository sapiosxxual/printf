#include "main.h"

/** PRINTING UNSIGNED NUMBER **/
/**
 * print_unsigned - prints an unsigned number
 * @types: the list of arguments
 * @buffer: the buffer array use to handle print
 * @flags: it calculates the active flags
 * @width: it is use to calculate the width
 * @precision: the precision spec
 * @size: specifying the size
 * Return: the characters printed
 */
int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '\0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '\0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/* print unsigned numb in octal form */
/**
 * print_octal - printing an unsigned numb in octal form
 * @types: list of the arguments
 * @buffer: buffer array to handle print
 * @flags: calculating the flags thats active
 * @width: calculating the width
 * @precision: specification of precision
 * @size: specifying of the size
 * Return: number of characters printed
 */
int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i--] = '\0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '\0';
		num /= 8;
	}
	if (flags && F_HASH && init_num != 0)
	{
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* printing unsigned number in hexadecimal */
/**
 * print_hexadecimal - printing an unsigned number in hexadecimal form
 * @types: list of the arguments
 * @buffer: the buffer array to be printed
 * @flags: calc flags that are active
 * @precision: specification of precision
 * @size: specifier of size
 * @width: the width to get
 * Return: the number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}
/** printing unsigned number in hexadecimal UPPER form **/
/**
 * print_hexa_upper - priting unsigned number in hexadecimal form
 * @types: list of all arguments
 * @buffer: buffer array handling the printing
 * @flags: calculation of active flogs
 * @width: calculatign the width
 * @precision: specification of precision
 * @size: specifying of size
 * Return: number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "012345678ABCDEF", buffer, flags, 'X',
				width, precision, size));
}
/** priting unsigned number in UPPER or lower **/
/**
 * print_hexa - prints a hexadecimal in either lower or upper
 * @types: the arguments
 * @map_to: Array of values to map the number on
 * @buffer: Buffer array to handle print
 * @flags: calc active flags
 * @flag_ch: calc active flags
 * @width: gets get the width
 * @size: size specifier
 * @precision: specification of precision
 * Return: numberof characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i--] = '\0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags && F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

