#include "main.h"
/**
 * handle_print - print argument based on any type
 * @pnt:  string to print the arguments.
 * @list: arguments to be printed.
 * @out: out
 * @buffer: buffer array to handle print.
 * @flags: active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *pnt, int *out, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	pnt_t pnt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; pnt_types[i].pnt != '\0'; i++)
		if (pnt[*out] == pnt_types[i].pnt)
			return (pnt_types[i].fn(list, buffer, flags, width,
						precision, size));
	if (pnt_types[i].pnt == '\0')
	{
		if (pnt[*out] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (pnt[*out - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*out);
			while (pnt[*out] != ' ' && pnt[*out] != '%')
				--(*out);
			if (pnt[*out] == ' ')
				--(*out);
			return (unknow_len);
		}
		return (printed_chars);
	}
}
