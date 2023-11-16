#include "shell.h"

/**
 * list_len - finds the link list of the random
 * @h: node to the head pointer is here
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - get arrays in the strings ss
 * @head: head to the first pointer
 *
 * Return: strungs of arrays
 */
char **list_to_strings(list_t *head)
{
	list_t *nd = head;
	size_t j = list_len(head), j;
	char **s;
	char *str;

	if (!head || !j)
		return (NULL);
	s = malloc(sizeof(char *) * (j + 1));
	if (!s)
		return (NULL);
	for (j = 0; nd; nd = nd->next, j++)
	{
		str = malloc(_strlen(nd->str) + 1);
		if (!str)
		{
			for (j = 0; j < j; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}

		str = _strcpy(str, nd->str);
		s[j] = str;
	}
	s[j] = NULL;
	return (s);
}


/**
 * print_list - display all the elements of linklists
 * @h: head to the first pointer
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - find the node index.
 * @node: head tp the pointer
 * @prefix: matching the string is here
 * @c: ixt thing id that did hard work 
  * Return: number one index is here
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *g = NULL;

	while (node)
	{
		g = starts_with(node->str, prefix);
		if (g && ((c == -1) || (*g == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - find the node index.
 * @head: head to the pointer is here needed
 * @node: node to the pointer is here
 *
 * Return: number one index is here
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}
