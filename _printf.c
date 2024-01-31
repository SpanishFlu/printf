#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_char - Print a single character
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - Print a string
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	return (write(1, str, 1));
}

/**
 * print_percent - Print the '%' character
 *
 * Return: Always 1 (number of characters printed)
 */
int print_percent(void)
{
	char percent = '%';

	return (write(1, &percent, 1));
}

/**
 * print_int - Print an integer
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int count = 0;

	count = snprintf(buffer, sizeof(buffer), "%d", num);
	return (write(1, buffer, count));
}

/**
 * _printf - Custom printf function
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;

			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_str(args);
			else if (*format == 'd' || *format == 'i')
				count += print_int(args);
			else if (*format == '%')
				count += print_percent();
			else
			{
				count += print_percent();
				count += write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (count);
}
