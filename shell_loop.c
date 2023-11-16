#include "shell.h"

/**
 * hsh - maasn she=lls loscs
 * @info: the params and return info structs
 * @av:  args vectors from main func
 *
 * Return: 0 and 1  when errors or errors cods
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_r = 0;

	while (r != -1 && builtin_r != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_r = find_builtin(info);
			if (builtin_r == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_r == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_r);
}

/**
 * find_builtin - seeks a built commands
 * @info: the params and return inf structs
 *
 * Return: -1 if built isno found,
 *			0 if built display successfully,
 *			1 if builtin found but not successful,
 *			-2 if built signal exits
 */
int find_builtin(info_t *info)
{
	int h, built_in = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (h = 0; builtintbl[i].type; h++)
		if (_strcmp(info->argv[0], builtintbl[h].type) == 0)
		{
			info->line_count++;
			built_in = builtintbl[h].func(info);
			break;
		}
	return (built_in);
}

/**
 * find_cmd - gets the path of the thing
 * @info: the params and return infs structs
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *pat = NULL;
	int d, m;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (d = 0, m = 0; info->arg[d]; d++)
		if (!is_delim(info->arg[d], " \t\n"))
			m++;
	if (!m)
		return;

	pat = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (pat)
	{
		info->path = pat;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd -  a an execut threads to rn cd
 * @info: the params and return infs structure
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
