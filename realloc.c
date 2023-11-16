#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the point to th mmory ara
 *@b: the bytes to fill *s wih the pointer
 *@n: the number of bites to be fill
 *Return: (s) memory to the pointer area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		s[k] = b;
	return (s);
}

/**
 * ffree - remove the momeries of code
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - removies a block of code memory
 * @ptr: pointer of comming malloc blocks
 * @old_size: byte size of previous block
 * @new_size: bytes of of new blocks
 *
 * Return: point to  block names.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *v;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	v = malloc(new_size);
	if (!v)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		v[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (v);
}
