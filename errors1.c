#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *k)
{
	int j = 0;
	unsigned long int rt = 0;

	if (*k == '+')
		k++;  /* TODO: why does it work like that ? */
	for (j = 0;  k[j] != '\0'; j++)
	{
		if (k[j] >= '0' && k[j] <= '9')
		{
			rt *= 10;
			rt += (k[j] - '0');
			if (rt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rt);
}

/**
 * print_error - prints the error sms
 * @info: params to be return
 * @estr: string conatain some errors
 * Return: 0 no erors return here some here 
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - it print a numbere here 
 * @input: the input
 * @fd: it descripts the file here 
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, co = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		co++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; i > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	co++;

	return (co);
}

/**
 * convert_number - used for converting a function
 * @num: nums
 * @base: based
 * @flags: stings flags
 *
 * Return: string
 */
char *convert_number(long int nm, int ba, int fl)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = nm;

	if (!(fl & CONVERT_UNSIGNED) && nm < 0)
	{
		n = -nm;
		sign = '-';

	}
	array = fl & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % ba];
		n /= ba;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function to replace a something
 * @buf: string of the address ara here
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
