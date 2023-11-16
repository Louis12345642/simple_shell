#include "shell.h"

/**
 * _strlen - return of leng ofs a strings
 * @s: the strings of leng to checks
 *
 * Return: integers lengths of strings
 */
int _strlen(char *s)
{
	int z = 0;

	if (!s)
		return (0);

	while (*s++)
		z++;
	return (z);
}

/**
 * _strcmp - performs cogarphic comparison of two strang.
 * @s1: the 1th strings
 * @s2: the 2th strings
 *
 * Return: minus while s1 < s2, plus while s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checking for needles the with hay
 * @haystack: string searching
 * @needle: the substring to find
 *
 * Return: addressing of nts chars of haying of nothing
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - connects the strings the together
 * @dest: the destinations buffers
 * @src: thes sources buffers
 *
 * Return: pointer to find the destination
 */
char *_strcat(char *dest, char *src)
{
	char *rets = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rets);
}
