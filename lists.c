#include "shell.h"

/**
 * add_node - address of the pointer in his head
 * @head: address if the head of the pointer
 * @str: str finding field of the code to work perfectly
 * @num: node perfect timing of the final node
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_hde;

	if (!head)
		return (NULL);
	new_hde = malloc(sizeof(list_t));
	if (!new_hde)
		return (NULL);
	_memset((void *)new_hde, 0, sizeof(list_t));
	new_hde->num = num;
	if (str)
	{
		new_hde->str = _strdup(str);
		if (!new_hde->str)
		{
			free(new_hde);
			return (NULL);
		}
	}
	new_hde->next = *head;
	*head = new_hde;
	return (new_hde);
}

/**
 * add_node_end - puts the node at the end of the
 * @head: adds the nodes at the end
 * @str: field string
 * @num: number of the node index
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_nd, *nd;

	if (!head)
		return (NULL);

	nd = *head;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	_memset((void *)new_nd, 0, sizeof(list_t));
	new_nd->num = num;
	if (str)
	{
		new_nd->str = _strdup(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
	}
	else
		*head = new_nd;
	return (new_nd);
}

/**
 * print_list_str - printts some of the linklist is here to finish
 * @h: node to the first pointer
 *
 * Return: list size of the project
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - removes node at given i
 * @head: pointers of the address is here
 * @index: delete index of node
 *
 * Return: 1 on success, 0 on fiure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nd, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *head;
	while (nd)
	{
		if (i == index)
		{
			prev_node->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		i++;
		prev_node = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * free_list - remove all the node lists
 * @head_ptr: pointer of the address is here
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *nd, *next_nd, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	nd = head;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->str);
		free(nd);
		nd = next_nd;
	}
	*head_ptr = NULL;
}
