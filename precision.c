#include "main.h"

/**
 * get_precision - precision for printing
 * @format: string in which to print the arguments
 * @i: arguments to be printed
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int tur_i = *i + 1;
	int precision = -1;

	if (format[tur_i] != '.')
		return (precision);
	precision = 0;
	for (tur_i += 1; format[tur_i] != '\0'; tur_i++)
	{
		if (is_digit(format[tur_i]))
		{
			precision *= 10;
			precision += format[tur_i] - '0';
		}
		else if (format[tur_i] == '*')
		{
			tur_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = tur_i - 1;
	return (precision);
}

