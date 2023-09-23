#include "main.h"
/**
 * handle_print - prints an argument based on type
 * @fmt: formatted string we are to print the arguments
 * @list: lists of argument to be printed
 * @ind: the index
 * @buffer: buffer array handling the printing
 * @flags: calc the actice flags
 * @width:  calculating the width
 * @precision: specifying precision
 * @size: specifier of size
 * Return: 1 or 2
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i;
	int unknownn_len = 0;
	int printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'x', print_hexadecimal}, {'p', print_pointer},
		{'o', print_octal}, {'X', print_hexa_upper}, {'r', print_reverse},
		{'S', print_non_printable}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision,
						size));
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknownn_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			unknownn_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' '  && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknownn_len += write(1, &fmt[*ind], 1);
		return (unknownn_len);
	}
	return (printed_chars);
}