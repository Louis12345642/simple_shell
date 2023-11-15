#include "shell.h"

/**
 *_eputs - printing an inputs stringing
 * @str: the stringing to be printed here

 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - writesing the characters could too sderr
 * @c: The character to printing the good.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set exactly here.
 */
int _eputchar(char c)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(2, buf, h);
		h = 0;
	}
	if (c != BUF_FLUSH)
		buf[h++] = c;
	return (1);
}

/**
 * _putfd - writing the characters c to given fd
 * @c: The charactering to printing
 * @fd: The filedesr to writes to
 *
 * Return: On success 1.
 * On error, -1 is returneds, and errnos is seting.
 */
int _putfd(char c, int fd)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(fd, buf, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buf[t++] = c;
	return (1);
}

/**
 *_putsfd - prints an inpujd t string
 * @str: the stringing to be printing
 * @fd: the files the  to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int t = 0;

	if (!str)
		return (0);
	while (*str)
	{
		t += _putfd(*str++, fd);
	}
	return (t);
}
