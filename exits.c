#include "shell.h"

/**
 **_strncpy - copies a string
 *@d: string to be copied
 *@st: the main string
 *@h: number of characters to copy
 *Return: conected charaters
 */
char *_strncpy(char *d, char *st, int h)
{
	int i, j;
	char *s = d;

	i = 0;
	while (st[i] != '\0' && i < h - 1)
	{
		d[i] = st[i];
		i++;
	}
	if (i < h)
	{
		j = i;
		while (j < h)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the number string
 *@scr: the number two string
 *@n: the amount the bytes
 *Return: the connected string
 */
char *_strncat(char *dest, char *scr, int n)
{
	int l, h;
	char *s = dest;

	l = 0;
	h = 0;
	while (dest[l] != '\0')
		l++;
	while (scr[h] != '\0' && h < n)
	{
		dest[l] = scr[h];
		l++;
		h++;
	}
	if (h < n)
		dest[l] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: parsing the string
 *@c: looking for the characters
 *Return: memory
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
