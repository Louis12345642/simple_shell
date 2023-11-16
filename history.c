#include "shell.h"

/**
 * get_history_file - find the file history
 * @inf: params structure
 *
 * Return: allocating string containing files
 */

char *get_history_file(info_t *inf)
{
	char *bu, *di;

	di = _getenv(inf, "HOME=");
	if (!di)
		return (NULL);
	bu = malloc(sizeof(char) * (_strlen(di) + _strlen(HIST_FILE) + 2));
	if (!bu)
		return (NULL);
	bu[0] = 0;
	_strcpy(bu, di);
	_strcat(bu, "/");
	_strcat(bu, HIST_FILE);
	return (bu);
}

/**
 * write_history - creating and apending files here 
 * @inf: the params structure
 *
 * Return: 1 or -1 failure
 */
int write_history(info_t *inf)
{
	ssize_t fdf;
	char *filname = get_history_file(inf);
	list_t *nd = NULL;

	if (!filname)
		return (-1);

	fdf = open(filname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filname);
	if (fdf == -1)
		return (-1);
	for (nd = inf->history; nd; nd = nd->next)
	{
		_putsfd(nd->str, fdf);
		_putfd('\n', fdf);
	}
	_putfd(BUF_FLUSH, fdf);
	close(fdf);
	return (1);
}

/**
 * read_history - reads the params history here
 * @inf: the params structure
 *
 * Return: histcount on success 0 otherwise
 */
int read_history(info_t *inf)
{
	int j, la = 0, lineco = 0;
	ssize_t fd, rdlen, fsiz = 0;
	struct stat st;
	char *buf = NULL, *filenm = get_history_file(inf);

	if (!filenm)
		return (0);

	fd = open(filenm, O_RDONLY);
	free(filenm);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsiz = st.st_size;
	if (fsiz < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsiz + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsiz);
	buf[fsiz] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (j = 0; j < fsiz; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			build_history_list(inf, buf + la, lineco++);
			la = j + 1;
		}
	if (la != j)
		build_history_list(inf, buf + la, lineco++);
	free(buf);
	inf->histcount = lineco;
	while (inf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(inf->history), 0);
	renumber_history(inf);
	return (inf->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
