#include "shell.h"

/**
 * is_cmd - finds if a file is an readable command
 * @info: the information structs
 * @path: position to the fiell
 *
 * Return: 1 , 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat str;

	(void)info;
	if (!path || stat(path, &str))
		return (0);

	if (str.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - repeats characters
 * @pathstr: sting paths string
 * @start: start the indexing
 * @stop: stop the indexing
 *
 * Return: pointers to new buf
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int h = 0, l = 0;

	for (l = 0, h = start; h < stop; h++)
		if (pathstr[h] != ':')
			buf[l++] = pathstr[h];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - finds this comanline in  pat strins
 * @info: the info struct
 * @pathstr: the way of string
 * @cmd: the cmd to look
 *
 * Return: full path of path inside thet
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int g = 0, curr_p = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[g] || pathstr[g] == ':')
		{
			path = dup_chars(pathstr, curr_p, g);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[g])
				break;
			curr_p = g;
		}
		g++;
	}
	return (NULL);
}
