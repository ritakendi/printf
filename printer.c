#include "main.h"
/**
 * _printf - produces output according to format
 * @format: format specifier pointer
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

