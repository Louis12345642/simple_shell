#include "shell.h"

/**
 * get_input - get the line without newline
 * @inf: params structure
 * @bu: buffer address
 * @le: adress length
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *inf, char **bu, size_t *le)
{
	ssize_t h = 0;
	size_t len_j = 0;

	if (!*le) /* feel the buffer if nothing left */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*bu);
		*bu = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		h = _getline(inf, bu, &len_j);
#endif
		if (h > 0)
		{
			if ((*bu)[h - 1] == '\n')
			{
				(*bu)[h - 1] = '\0'; /* remove the newline */
				h--;
			}
			inf->linecount_flag = 1;
			remove_comments(*bu);
			build_history_list(inf, *bu, inf->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = h;
				inf->cmd_buf = bu;
			}
		}
	}
	return (h);
}

/**
 * get_input - get the line without newline
 * @inf: params structures
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *inf)
{
	static char *buf; /* the ';' cond the buffer */
	static size_t h, g, len;
	ssize_t r = 0;
	char **bufp = &(inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(inf, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* commdand left in the prompt */
	{
		g = h; /* initial a iterater */
		p = buf + h; /* repeats the pointer */

		check_chain(inf, buf, &g, h, len);
		while (g < len) /* iterate the simbols simcol */
		{
			if (is_chain(inf, buf, &g))
				break;
			g++;
		}

		h = g + 1; /* incement the the last thing ';'' */
		if (h >= len) /* check if it reach the end? */
		{
			h = len = 0; /* chenges the partions */
			inf->cmd_buf_type = CMD_NORM;
		}

		*bufp = p; /* changes the pointer to the next code line */
		return (_strlen(p)); /* gets the length of the available command */
	}

	*bufp = buf; /* if not pass back the next buffer*/
	return (r); /* get the size of the buffer */
}

/**
 * read_buf - reads the current buuffer
 * @inf: param structure
 * @buf: buffer
 * @j: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *inf, char *buf, size_t *j)
{
	ssize_t g = 0;

	if (*j)
		return (0);
	g = read(inf->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*j = g;
	return (g);
}

/**
* get_ - get the line without nextline
 * @inf: params structure
 * @pt: pointers address ot the next code
 * @leng: preacllocated size of the memory is here
 *
 * Return: d
 */
int _getline(info_t *inf, char **pt, size_t *leng)
{
	static char buf[READ_BUF_SIZE];
	static size_t g, len;
	size_t f;
	ssize_t o = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pt;
	if (p && leng)
		s = *leng;
	if (g == len)
		g = len = 0;

	o = read_buf(inf, buf, &len);
	if (o == -1 || (o == 0 && len == 0))
		return (-1);

	c = _strchr(buf + g, '\n');
	f = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + f : f + 1);
	if (!new_p) /* malloc may fail */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + g, f - g);
	else
		_strncpy(new_p, buf + i, f - g + 1);

	s += f - g;
	g = f;
	p = new_p;

	if (leng)
		*leng = s;
	*pt = p;
	return (s);
}

/**
* get_input - get the line without ctr+c
 * @sig_n: number of signal
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_n)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
