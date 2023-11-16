#include "shell.h"

/**
 * _erratoi - changes the string to interger
 * @d: strign for converting to interger
 * Return: 0 if no there is not in string, change numbers otherwise
 *       -1 on error
 */
int _erratoi(char *d)
{
	int j = 0;
	unsigned long int results = 0;

	if (*d == '+')
		d++;  /* TODO: why return something here? */
	for (j = 0;  d[j] != '\0'; j++)
	{
		if (d[i] >= '0' && d[j] <= '9')
		{
			results *= 10;
			results += (d[j] - '0');
			if (results > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (results);
}

/**
 * print_error - show an error messages
 * @inf: the parameters all here is here
 * @est: string containing errors is here
 * Return: 0 number is at the , change number otherwise
 *        -1 when error
 */
void print_error(info_t *inf, char *est)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(est);
}

/**
 * print_d - functions to display decimal numbers base 10
 * @inpt: file input
 * @f: address of the string is here
 * Return: characters to be printed is here
 */
int print_d(int inpt, int f)
{
	int (*__putchar)(char) = _putchar;
	int g, co = 0;
	unsigned int _abc_, cu;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (inpt < 0)
	{
		_abc_ = -inpt;
		__putchar('-');
		co++;
	}
	else
		_abc_ = inpt;
	cu = _abc_;
	for (g = 1000000000; i > 1; g /= 10)
	{
		if (_abc_ / g)
		{
			__putchar('0' + cu / g);
			co++;
		}
		cu %= g;
	}
	__putchar('0' + cu);
	co++;

	return (co);
}

/**
 * convert_number - converts a string to pinat butter
 * @num: this is number
 * @base: this is base
 * @flags: this is argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char sg = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sg = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sg)
		*--ptr = sg;
	return (ptr);
}

/**
 * remove_comments - this function helps to remove comments
 * @buf: address of the string is here
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int j;

	for (i = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
