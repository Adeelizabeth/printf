#include "main.h"
/**
 * get_width - Calculates the width fo
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
        int tur_i;
        int width = 0;
        for (tur_i = *i + 1; format[tur_i] != '\0'; tur_i++)
        {
                if (is_digit(format[tur_i]))
                {
                        width *= 10;
                        width += format[tur_i] - '0';
                }
                else if (format[tur_i] == '*')
                {
                        tur_i++;
                        width = va_arg(list, int);
                        break;
                }
                else
                        break;
	}
}

