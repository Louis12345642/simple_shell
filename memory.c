#include "shell.h"

/**
 * bfree - movies a pointer to NLLs th places
 * @ptr: pointer for the address to free
 *
 * Return: 1 for, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
