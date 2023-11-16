#include "shell.h"

/**
 * **strtow - sperates a string into sentence.  dels are ignored
 * @str: the input strings
 * @d: the delimeter string
 * Return: a fointer to an of array of string, of not on failing
 */

char **strtow(char *str, char *d)
{
	int x, j, k, q, numwos = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[i], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwos++;

	if (numwos == 0)
		return (NULL);
	s = malloc((1 + numwos) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, j = 0; j < numwos; j++)
	{
		while (is_delim(str[x], d))
			i++;
		k = 0;
		while (!is_delim(str[x + k], d) && str[x + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < k; q++)
			s[j][q] = str[x++];
		s[j][q] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - separates a string into sent
 * @str: thee inputing strings
 * @d: the delimeter
 * Return: a find to an arrays of strings, or not on fail
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
