#include "shell.h"

/**
 * _strcpy - finds the strings here
 * @dest: the place ending
 * @src: the ending place in the place
 *
 * Return: God helping hands
 */
char *_strcpy(char *dest, char *src)
{
	int g = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[g])
	{
		dest[g] = src[g];
		g++;
	}
	dest[g] = 0;
	return (dest);
}

/**
 * _strdup - repeats a string
 * @str: the string to repeats
 *
 * Return: pointer to the repeats string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *rs;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	rs = malloc(sizeof(char) * (len + 1));
	if (!rs)
		return (NULL);
	for (len++; len--;)
		rs[len] = *--str;
	return (rs);
}

/**
 *_puts - displays an input strings
 *@str: the string to be display
 *
 * Return: void
 */
void _puts(char *str)
{
	int h = 0;

	if (!str)
		return;
	while (str[h] != '\0')
	{
		_putchar(str[h]);
		h++;
	}
}

/**
 * _putchar - finds the char cc to stout
 * @c: The character to display
 *
 * Return: On fullfilment 1.
 * On error, -1 is returned, and errno is set accordingly.
 */
int _putchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
