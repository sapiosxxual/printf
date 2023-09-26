#include "main.h"
/**
 * handle_write_char - printing a string
 * @c: charcater types
 * @buffer: buffer of array to handle printing
 * @flags: calculating the active flags
 * @size: specifier of size
 * @width: lets get the width
 * @precision: precisin specifier
 * Return: the count of charcters printed
 */
int handle_write_char(char c, char buffer[], int flags, int width, int
		precision, int size);
int write_number(int is_negative, int ind, char buffer[], int flags, int
		width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int precision, int
		length, char padd, char extra_c);
int handle_write_char(char c, char buffer[], int flags, int width, int
		precision, int size)
{/* padding at bufer's right and character is stored at left */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags && F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - 2 - i] = padd;
		if (flags && F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - 1 -
						i], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + write(1,
						&buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - printing a string
 * @ind: character types
 * @size: specifying size
 * @is_negative: list of arguments
 * @precision: specifier of precision
 * @width: lets get the width
 * @flags: calc the active flags
 * @buffer: buffer of array handling printing
 * Return: count of chrcters prnted
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int
		width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags && F_ZERO) && !(flags && F_MINUS))
		padd = 0;
	if (is_negative)
		extra_ch = '-';
	if (flags && F_PLUS)
		extra_ch = '+';
	if (flags && F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flags, width, precision, length, padd,
				extra_ch));
}
/**
 * write_num - using buffer to write a number
 * @ind: starting point of the buffer
 * @bufr: the buffer used
 * @flags: lets get the flags
 * @width: lets get the width
 * @prec: precision specifier
 * @extra_c: extra character
 * @padd: padding character
 * @length: the length of number
 * Return: the number of printed characters
 */
int write_num(int ind, char bufr[], int flags, int width, int prec, int
		length, char extra_c, char padd)
{
	int i = 1, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && width == 0 && bufr[ind] == '0')
		return (0);/* printf(".0d", 0) no character is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && bufr[ind] == '0')
		bufr[ind] = padd = ' ';/* Displaying width with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (length < prec)
		bufr[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (length < width)
	{
		for (i = 1; i < width - length + 1; i++)
			bufr[i] = padd;
		bufr[i] = '\0';
		if (flags && F_MINUS && padd == ' ')
		{/* assigning an extra character to the left of buffer */
			if (extra_c)
				bufr[--ind] = extra_c;
			return (write(1, &bufr[ind], length) + write(1, &bufr[1], i - 1));
		}
		else if (!(flags && F_MINUS) && padd == ' ')
		{/* extra character to the left of buffer */
			if (extra_c)
				bufr[--ind] = extra_c;
			return (write(1, &bufr[i], i - 1) + write(1, &bufr[ind], length));
		}
		else if (!(flags && F_MINUS) && padd == '0')
		{/*extra character to the left of padd */
			if (extra_c)
				bufr[--padd_start] = extra_c;
			return (write(1, &bufr[padd_start], i - padd_start) + write(1,
						&bufr[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		bufr[--ind] = extra_c;
	return (write(1, &bufr[ind], length));
}
/**
 * write_unsgnd - writing an unsigned number
 * @is_negative: the number that indicates if the number is negative
 * @ind: startng point of the number in the buffer
 * @buffer: buffer of array
 * @width: width specifier
 * @size: size specifier
 * @flags: specifying flags
 * @precision: specifying precision
 * Return: amount of charcater printed
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,
		int precision, int size)
{/* starttng at postion i and the number is stored at the right of buffer */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (length < precision)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (length < width)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{/* character is assigned to the left of buffer [padd > buffer] */
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
		return (write(1, &buffer[ind], length));
	}
	/**
	 * write_pointer - writjg the address of a memory
	 * @buffer: buffer of charcaters
	 * @ind: index/starting pont atehuc the buffer start writing
	 * @length: the length of the number
	 * @width: specifying the width
	 * @flags: specifying flags
	 * @padd: character rprsnting padding
	 * @extra_c: rep extra character
	 * @padd_start: starting point for padding
	 * Return: the numbers of wrriten chracters
	 */
	int write_pointer(char buffer[], int ind, int length, int width, int flags,
			char padd, char extra_c, int padd_start)
	{
		int i;

		if (width < length)
		{
			for (i = 3; i < width - length + 3; i++)
				buffer[i] = padd;
			buffer[i] = '\0';
			if (flags & F_MINUS && padd == ' ')
			{/* extra character is assigned to the left of buffer */
				buffer[--ind] = 'x';
				buffer[--ind] = '0';
				if (extra_c)
					buffer[--ind] = extra_c;
				return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
			}
			else if (!(flags & F_MINUS) && padd == ' ')
			{/* assigning extra charcater at the left f buffer */
				buffer[--ind] = 'x';
				buffer[--ind] = '0';
				if (extra_c)
					buffer[--ind] = extra_c;
				return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
			}
			else if (!(flags & F_MINUS) && padd == '0')
			{/* assngng an extra character a tje ledt of padd */
				if (extra_c)
					buffer[--padd_start] = extra_c;
				buffer[1] = '0';
				buffer[2] = 'x';
				return (write(1, &buffer[padd_start], i - padd_start) + write(1,
							&buffer[ind], length - (1 - padd_start) - 2));
			}
		}
		buffer[--ind] = 'x';
		buffer[--ind] = '0';
		if (extra_c)
			buffer[--ind] = extra_c;
		return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
	}
