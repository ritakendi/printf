#include "main.h"
/**
 * _printf - produces output according to format
 * @format: format specifier pointer
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*pfunc)(va_list, char *, unsigned int);
	char *b;
	unsigned int i = 0, j = 0, length = 0;

	va_start(args, format),	b = malloc(sizeof(char) * 1024);
	if (!format || !b || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(b, j), free(b), va_end(args);
				return (-1);
			}
			else
			{	pfunc = get_print_func(format, i + 1);
				if (pfunc == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(b, format[i], j), length++, i--;
				}
				else
				{
					length += pfunc(args, b, j);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(b, format[i], j), length++;
		for (j = length; j > 1024; j -= 1024)
			;
	}
	print_buf(b, j), free(b), va_end(args);
	return (length);
}
