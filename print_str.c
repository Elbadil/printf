#include "main.h"
/**
 * print_str - print a string to stdout
 * @args: variadic parameter
 * Return: number of charater printed
*/
int print_str(va_list args)
{
	int count = 0;
	char *s;

	s = va_arg(args, char*);
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
