#include "main.h"
/**
 * _printf - to print all format
 * @format: format parameter
 * Return: characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, value = 0;
	int (*f)(va_list);
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count += value;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_format(&format[i + 1]);
			if (f != NULL)
			{
				value = f(args);
				count += value;
				i = i + 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i], 1);
				count += value;
				i = i + 2;
				continue;
			}
		}
	}
	return (count);
}
