#include "main.h"
/**
 * get_flags - calculating active flags
 * @format: the formatted string we are to print the arguments
 * @i: takimg a parameter
 * Return: the actuve flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j;
	int curry_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curry_i = *i + 1; format[curry_i] != '\0'; curry_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curry_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
		}
	}
	*i = curry_i - 1;
	return (flags);
}
