#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - this is a printf function
 * @format: format to be printed
 * Return: the printed characters
 */
int _printf(char *format);
int _printf(char *format, ...)
{
	int i;
	int printed = 0;
	int printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_index);
			}
			/* write(1, &format[i], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags, width,
					precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_index);

	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - it prints the content of the buffer if it exist
 * @buffer: array of characters
 * @buff_index: the index which will next character, representing the length
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	{
		write(1, &buffer[0], *buff_index);
	}
	*buff_index = 0;
}
