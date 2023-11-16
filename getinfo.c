#include "shell.h"

/**
 * clear_info - initials the struct
 * @inf: structure position address
 */
void clear_info(info_t *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
 * set_info - stet info structure
 * @inf: struct address
 * @pv:params vector
 */
void set_info(info_t *inf, char **pv)
{
	int j = 0;

	inf->fname = pv[0];
	if (inf->arg)
	{
		inf->argv = strtow(inf->arg, " \t");
		if (!inf->argv)
		{

			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strdup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (j = 0; inf->argv && inf->argv[j]; j++)
			;
		inf->argc = j;

		replace_alias(inf);
		replace_vars(inf);
	}
}

/**
 * free_info - make the struct_t free
 * @inf: s
 * @l: free all the memeries
 */
void free_info(info_t *inf, int l)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (l)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			free_list(&(inf->env));
		if (inf->history)
			free_list(&(inf->history));
		if (inf->alias)
			free_list(&(inf->alias));
		ffree(inf->environ);
			inf->environ = NULL;
		bfree((void **)inf->cmd_buf);
		if (inf->readfd > 2)
			close(inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
