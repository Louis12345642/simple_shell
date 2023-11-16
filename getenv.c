#include "shell.h"

/**
  * _get_environ - get ride of env variables
 * @inf: maintaining structueres are here
 *        cons function prototypes.
 * Return: Always 0
 */
char **get_environ(info_t *inf)
{
	if (!inf->environ || info->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _unsetenv - get ride of env variables
 * @inf: maintaining structueres are here
 *        cons function prototypes.
 *  Return: 1 on removing, 0 wiselike
 * @va: the env string variable
 */
int _unsetenv(info_t *inf, char *va)
{
	list_t *nd = inf->env;
	size_t k = 0;
	char *q;

	if (!nd || !va)
		return (0);

	while (nd)
	{
		q = starts_with(nd->str, va);
		if (q && *q == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), k);
			k = 0;
			nd = inf->env;
			continue;
		}
		nd = nd->next;
		k++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - create a new env variable,
 * @in: maintaining structure here is a value
 * @va: the variable here is a thing
 * @vac: the variable here is a thing here code
 *  Return: Always 0
 */
int _setenv(info_t *in, char *va, char *vac)
{
	char *bu = NULL;
	list_t *nd;
	char *p;

	if (!va || !vac)
		return (0);

	bu = malloc(_strlen(va) + _strlen(vac) + 2);
	if (!bu)
		return (1);
	_strcpy(bu, va);
	_strcat(bu, "=");
	_strcat(bu, vac);
	nd = in->env;
	while (nd)
	{
		p = starts_with(nd->str, va);
		if (p && *p == '=')
		{
			free(nd->str);
			nd->str = bu;
			info->env_changed = 1;
			return (0);
		}
		nd = nd->next;
	}
	add_node_end(&(in->env), bu, 0);
	free(bu);
	in->env_changed = 1;
	return (0);
}
